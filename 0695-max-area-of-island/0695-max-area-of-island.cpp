class Solution {
public:
int bfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis)
    {
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        int areaOfThisIsland = 1;

        q.push({row, col});
        int n = grid.size();
        int m = grid[0].size();

        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            //traverse in the all directions(4) & make the neighbors visited

            int delrow[] = {-1, 0, 1, 0}; // Up, Right, Down, Left
            int delcol[] = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++) { // Loop over 4 possible directions
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                grid[nrow][ncol] == 1 && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                    areaOfThisIsland++;
                }
            }
        }
        return areaOfThisIsland;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m,0));
        int maxAreaOfIsland = 0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1 and !vis[i][j])
                {
                    int areaOfIsland = bfs(i,j,grid,vis);
                    maxAreaOfIsland = max(maxAreaOfIsland, areaOfIsland);
                }
            }
        }
        return maxAreaOfIsland;
    }
};