class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		int islands = 0;
		for (int i = 0; i < grid.size(); i++) 
			for (int j = 0; j < grid[i].size(); j++) 
				if (grid[i][j] == '1' && ++islands) 
					numIslands_helper(grid, i, j);
		return islands;
	}

	void numIslands_helper(vector<vector<char>>& grid, int i, int j) {
		if (i >= 0 && i < grid.size() && j >= 0 && j < grid[i].size() && grid[i][j] == '1') {
			grid[i][j] = '0';
			numIslands_helper(grid, i, j + 1);
			numIslands_helper(grid, i + 1, j);
			numIslands_helper(grid, i, j - 1);
			numIslands_helper(grid, i - 1, j);
		}
	}
};
