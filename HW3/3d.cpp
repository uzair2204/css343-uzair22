class Solution {
public:
	//Main function
	bool exist(vector<vector<char>>& board, string word) {
		vector<vector<bool>> check(board.size(), vector<bool>(board[0].size(), false));
		//Iterate through each position on the board and checks to see if it is equal 
		//to the word passed in.
		for (int i = 0; i < board.size(); i++)
			for (int j = 0; j < board[i].size(); j++)
				if (board[i][j] == word[0] && process_helper(board, check, word, 0, i, j))
					//Return true if word is found
					return true;
		
		//Return false if word is not found
		return false;
	}
	
	//Helper function. It iterates throiugh each position on the board and checks to see if they are equal to what's passed
	//in as well as checking for matches with other positions around them. (e.g. i < 0 || j < 0)
	bool process_helper(vector<vector<char>>& board, vector<vector<bool>>& check, string word, int index, int i, int j) {
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

