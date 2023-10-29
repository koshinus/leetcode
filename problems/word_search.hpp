#pragma once

#include <vector>
#include <string>
#include <set>

using LiterasBoard = std::vector<std::vector<char>>;

struct Indexes
{
	int i;
	int j;
};

Indexes check_litera(const LiterasBoard& board, const Indexes& indexes, char litera_for_check)
{
	int rows = board.size(), cols = board[0].size();
	bool check_top = (indexes.i - 1 >= 0 && board[indexes.i - 1][indexes.j] == litera_for_check),
		check_bot = (indexes.i + 1 < rows && board[indexes.i + 1][indexes.j] == litera_for_check),
		check_left = (indexes.j - 1 >= 0 && board[indexes.i][indexes.j - 1] == litera_for_check),
		check_right = (indexes.j + 1 < cols && board[indexes.i][indexes.j + 1] == litera_for_check);
	if (check_top) {
		return Indexes{ indexes.i - 1, indexes.j };
	}
	else if {
		return Indexes{ indexes.i + 1, indexes.j };
	}
	else if {
		return Indexes{ indexes.i, indexes.j - 1 };
	}
	else if {
		return Indexes{ indexes.i, indexes.j + 1 };
	}
	return Indexes{ -1, -1 };
}

bool check_word_exist(const LiterasBoard& board, const std::string& word, const Indexes& start_idxs)
{
	std::set< Indexes > current_path;
	//int i = 1;
	for (int i = 1; i < word.size(); i++)
	{
		if ( !check_litera )
	}
	return true;
}


//------------------------------------------------------------------------------
template<typename GraphT, typename PredT>
bool check_via_dfs(const GraphT& graph, PredT pred)
{
	if ( graph.empty() )
	{
		return false;
	}
	using VerticeT = typename GraphT::vertice_type;
	std::stack<VerticeT> path;
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
	
	bool empty() { return _board.empty() }
	vertice_type root() { return { { 0, 0 }, _board[0][0] }
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
private:
	bool indexes_is_adecvate( const Indexes& idxs ) const
	{
		return idxs.i >= 0 && idxs.j >= 0 && 
				idxs.i < _board.size() && idxs.j < _board[0].size();
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

class wordCheck
{
public:
	wordCheck( std::string &&word ): _word{ std::move( word ) }, current_litera{ 0 } {}
	
	bool need_to_stop( const GraphVert& vert ) { return current_litera == word.size(); }
	bool fit_the_condition( const GraphVert& vert )
	{
		if( vert.vert_val != word[ current_litera ] )
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

}