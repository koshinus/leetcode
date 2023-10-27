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

bool exist(LiterasBoard& board, std::string word)
{

}