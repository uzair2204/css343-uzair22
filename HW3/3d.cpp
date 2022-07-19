class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		vector<vector<bool>> check(board.size(), vector<bool>(board[0].size(), false));
		for (int i = 0; i < board.size(); i++)
			for (int j = 0; j < board[i].size(); j++)
				if (board[i][j] == word[0] && process_helper(board, check, word, 0, i, j))
					return true;

		return false;
	}

	bool process_helper(vector<vector<char>>& board, vector<vector<bool>>& check, string word, int index, int i, int j)
	{
		if (index >= word.length())
			return true;
		if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || check[i][j] || board[i][j] != word[index])
			return false;
		check[i][j] = true;
		return process_helper(board, check, word, index + 1, i - 1, j)
		|| process_helper(board, check, word, index + 1, i + 1, j)
		|| process_helper(board, check, word, index + 1, i, j - 1)
		|| process_helper(board, check, word, index + 1, i, j + 1)
		|| (check[i][j] = false);
	}

};

