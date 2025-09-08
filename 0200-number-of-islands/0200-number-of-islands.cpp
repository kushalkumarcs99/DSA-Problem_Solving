class Solution {
public:
    void dfs(int row, int column, vector<vector<char>>& grid,vector<vector<bool>>& visited)
    {
        visited[row][column] = true;
        int rows = grid.size();
        int columns = grid[0].size();
        vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};

        for(int i=0;i<4;i++)
        {
            int nrow = row + directions[i].first;
            int ncol = column + directions[i].second;
            if(nrow >= 0 && nrow < rows && ncol >= 0 && ncol < columns && 
            grid[nrow][ncol]=='1' && !visited[nrow][ncol])
            {
                dfs(nrow, ncol, grid, visited);
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m,false));
        int result = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == '1' and visited[i][j]==false)
                {
                    dfs(i,j,grid,visited);
                    result++;
                }
            }
        }
        return result;
    }
};