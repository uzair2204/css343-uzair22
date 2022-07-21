class Solution {
public:
	//Main function
	int numIslands(vector<vector<char>>& grid) {
		int islands = 0;
		//Loops through each row in the grid to see if it contains a 1 or not.
		// If so, it increments numIslands by one.
		for (int i = 0; i < grid.size(); i++) 
			for (int j = 0; j < grid[i].size(); j++) 
				if (grid[i][j] == '1' && ++islands) 
					numIslands_helper(grid, i, j);
		//Return how many islands there are on this particular grid
		return islands;
	}
	
	//Helper function that iterates through the grid and changes each '1' to a '0'
	void numIslands_helper(vector<vector<char>>& grid, int i, int j) {
		//Check if the current position is within the bounds of the grid.
		if (i >= 0 && i < grid.size() && j >= 0 && j < grid[i].size() && grid[i][j] == '1') {
			grid[i][j] = '0';
			//Recursive calls
			numIslands_helper(grid, i, j + 1);
			numIslands_helper(grid, i + 1, j);
			numIslands_helper(grid, i, j - 1);
			numIslands_helper(grid, i - 1, j);
		}
	}
};
