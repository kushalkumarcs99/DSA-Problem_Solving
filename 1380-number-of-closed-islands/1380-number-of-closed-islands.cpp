class Solution {
public:
    int rows, cols;
    void dfs(vector<vector<int>>& grid, int row, int col)
    {
        if(row < 0 || col < 0 || row >= rows || col >= cols) return;
        if(grid[row][col] != 0) return;

        grid[row][col] = 1;

        dfs(grid,row+1,col);
        dfs(grid,row-1,col);
        dfs(grid,row,col+1);
        dfs(grid,row,col-1);
    }
    int closedIsland(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;

        rows = grid.size();
        cols = grid[0].size();

        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if((i == 0 || j == 0 || i == rows-1 || j == cols-1) && grid[i][j]==0)
                {
                    dfs(grid,i,j);
                }
            }
        }

        int ans = 0;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==0)
                {
                    dfs(grid,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};