class Solution {
public:
    void dfsHelper(int row, int column, vector<vector<char>>& grid)
    {
        grid[row][column] = '0';
        int rows = grid.size();
        int columns = grid[0].size();
        vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};

        for(int i=0;i<4;i++)
        {
            int nrow = row + directions[i].first;
            int ncol = column + directions[i].second;
            if(nrow >= 0 && nrow < rows && ncol >= 0 && ncol < columns && 
            grid[nrow][ncol]=='1')
            {
                dfsHelper(nrow, ncol, grid);
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int numberOfIslands = 0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    numberOfIslands++;
                    dfsHelper(i,j,grid);
                }
            }
        }
        return numberOfIslands;
    }
};