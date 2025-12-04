class Solution {
public:
    int dfsHelper(int row, int column, vector<vector<int>>& grid)
    {
        grid[row][column] = 0;
        int rows = grid.size();
        int columns = grid[0].size();

        int currentArea = 1;

        vector<pair<int, int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};

        for(int i=0;i<4;i++)
        {
            int nrow = row + directions[i].first;
            int ncol = column + directions[i].second;

            if(nrow >= 0 && nrow < rows && ncol >= 0 && ncol < columns && grid[nrow][ncol]==1)
            {
                currentArea += dfsHelper(nrow, ncol, grid);
            }
        }

        return currentArea;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();

        int maxAreaOfIsland = 0;

        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<columns;j++)
            {
                if(grid[i][j] == 1)
                {
                    int currentIslandArea = dfsHelper(i,j, grid);
                    maxAreaOfIsland = max(maxAreaOfIsland, currentIslandArea);
                }
            }
        }
        return maxAreaOfIsland;
    }
};