#pragma once

#include <vector>
#include <string>
#include <set>
#include <stack>

//#include "support_func.hpp"

using LiterasBoard = std::vector<std::vector<char>>;

struct Indexes
{
	int i;
	int j;

	bool operator==( const Indexes& other )
	{
		return i == other.i && j == other.j;
	}
};

bool operator<(const Indexes& left, const Indexes& right)
{
	return left.i < right.i || left.j < right.j;
}

template<typename T>
class _Stack
{
public:
	_Stack() : stack_{} {}
	T pop()
	{
		auto val = stack_.top();
		stack_.pop();
		return val;
	}
	void push( T val ) { stack_.push( val ); }
	bool empty() { return stack_.empty(); }
private:
	std::stack<T> stack_;
};

template<typename GraphT, typename StackT, typename PredT>
bool check_via_dfs( GraphT& graph, PredT& pred )
{
	if ( graph.empty() )
	{
		return false;
	}
	using VerticeT = typename GraphT::vertice_type;
	StackT path;
	path.push( graph.root() );
	while( !path.empty() )
	{
		auto cur_vert = path.pop();
		if( pred.need_to_stop( cur_vert ) )
		{
			return true;
		}
		if( pred.fit_the_condition( cur_vert ) )
		{
			auto kids = graph.get_children( cur_vert );
			if( kids.empty() )
			{
				pred.step_back();
				graph.step_back( cur_vert );
				continue;
			}
			for( auto&& kid: kids )
			{
				path.push( kid );
			}
		}
	}
	return false;
}

struct GraphVert
{
	Indexes idxs;
	char vert_val;
};

class Graph
{
public:
	using vertice_type = GraphVert;
	
	Graph( LiterasBoard&& board ) : _board{ std::move( board ) }, _visited{} {}
	
	bool empty() const { return _board.empty(); }
	vertice_type root() { return { { 0, 0 }, _board[0][0] }; }
	std::vector<GraphVert> get_children( const vertice_type& vertice )
	{
		auto& v_idxs = vertice.idxs;
		std::vector<GraphVert> children;
		add_child_with_check( children, { v_idxs.i + 1, v_idxs.j } );
		add_child_with_check( children, { v_idxs.i - 1, v_idxs.j } );
		add_child_with_check( children, { v_idxs.i, v_idxs.j + 1 } );
		add_child_with_check( children, { v_idxs.i, v_idxs.j - 1 } );
		return children;
	}
	void step_back( const vertice_type& v ) { _visited.erase( v.idxs ); }
private:
	bool indexes_is_adecvate( const Indexes& idxs ) const
	{
		return idxs.i >= 0 && idxs.j >= 0 && 
				idxs.i < _board.size() && idxs.j < _board.front().size();
	}
	
	bool already_visited( Indexes child_idxs ) const
	{
		return _visited.find( child_idxs ) != _visited.end();
	}
	
	void add_child_with_check( std::vector<GraphVert>& children, Indexes child_idxs )
	{
		if ( indexes_is_adecvate( child_idxs ) && !already_visited( child_idxs ) )
		{
			children.push_back( { { child_idxs.i, child_idxs.j }, _board[child_idxs.i][child_idxs.j] } );
			_visited.insert( child_idxs );
		}
	}
	
	std::set<Indexes> _visited;
	LiterasBoard _board;
};

class WordCheck
{
public:
	WordCheck( std::string &&word ): _word{ std::move( word ) }, current_litera{ 0 } {}
	
	bool need_to_stop( const GraphVert& vert ) { return current_litera == _word.size(); }
	bool fit_the_condition( const GraphVert& vert )
	{
		if( vert.vert_val != _word[ current_litera ] )
		{
			return false;
		}
		current_litera++;
		return true;
	}
	void step_back()
	{
		if( current_litera > 0 )
		{
			current_litera--;
		}
	}

private:
	size_t current_litera;
	std::string _word;
};

bool exist(LiterasBoard& board, std::string word)
{
	WordCheck checker( std::move( word ) );
	Graph graph( std::move( board ) );
	return check_via_dfs<Graph, _Stack<Graph::vertice_type>, WordCheck>( graph, checker );
}


namespace word_search
{

void run_tests()
{
    std::vector<std::vector<char>> mat{ {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'} };
    std::string word = "SEE";
    support::print_matrix( mat );
    std::cout << exist( mat, word );
}

}
