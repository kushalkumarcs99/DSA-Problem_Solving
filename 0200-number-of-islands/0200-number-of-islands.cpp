class Solution {
public:
    void DFS(int row, int column, vector<vector<char>>& grid, vector<vector<bool>>& visited)
    {
        visited[row][column] = true;
        int rows = grid.size();
        int columns = grid[0].size();

        vector<int> dr = {-1,1,0,0};
        vector<int> dc = {0,0,-1,1};

        for(int i=0;i<4;i++)
        {
            int nrow = row + dr[i];
            int ncol = column + dc[i];
            if(nrow >= 0 && nrow < rows && ncol >= 0 && ncol < columns && 
            grid[nrow][ncol]=='1' && !visited[nrow][ncol])
            {
                DFS(nrow, ncol, grid, visited);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        vector<vector<bool>> visited(rows,vector<bool>(columns,false));
        int numberOfIslands = 0;
        for(int row = 0;row < rows;row++)
        {
            for(int column = 0;column < columns;column++)
            {
                if(grid[row][column] == '1' && !visited[row][column])
                {
                    numberOfIslands++;
                    DFS(row,column,grid,visited);
                }
            }
        }
        return numberOfIslands;
    }
};