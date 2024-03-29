class Solution
{
public:
    struct Position {
        int row, col;
        Position(int row, int col) : row(row), col(col) {}
        Position(const Position& pos) : row(pos.row), col(pos.col) {}
    };
    
    //Main function
    int shortestBridge(vector<vector<int>>& grid) {
        //create an empty vector of Position objects
        vector<Position> x, y;
        bool first = true;
        //Iterate through each row of the grid and for each iteration 
        //it creates a new Position object with its row equal to that iteration's 
        //current row number and its col equal to that iteration's current column number.
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    if (first) {
                        shortestBridge_helper(grid, x, i, j);
                        first = false;
                    }
                    else {
                        shortestBridge_helper(grid, y, i, j);
                        i = grid.size();
                        break;
                    }
                }
            }
        }
        int result = INT_MAX;
        //Another loop over every column of the grid where it checks if any cells are set to one using 
        //an if statement nested inside itself again checking for redundancy within itself since these 
        //steps could also be done once before when going through every row of the grid previously.
        for (int i = 0; i < x.size(); i++)
            for (int j = 0; j < y.size(); j++)
                result = min(result, abs(x[i].row - y[j].row) + abs(x[i].col - y[j].col) - 1);
        return result;
    }
    
    //Helper function
    void shortestBridge_helper(vector<vector<int>>& grid, vector<Position>& v, int r, int c) {
        if (r >= 0 && r < grid.size() && c >= 0 && c < grid[r].size() && grid[r][c] != 0) {
            v.push_back(Position(r, c));
            grid[r][c] = 0;
            //Recursive calls
            shortestBridge_helper(grid, v, r + 1, c);
            shortestBridge_helper(grid, v, r - 1, c);
            shortestBridge_helper(grid, v, r, c - 1);
            shortestBridge_helper(grid, v, r, c + 1);
        }
    }
};

