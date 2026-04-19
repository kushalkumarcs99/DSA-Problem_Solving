class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& visited)
    {
        visited[i][j] = 1;
        int n = grid.size();
        int m = grid[0].size();

        vector<pair<int, int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};

        for(auto dir : dirs)
        {
            int nx = i + dir.first;
            int ny = j + dir.second;

            if(nx >= 0 && nx < n && ny >= 0 && ny < m && visited[nx][ny] == 0 && grid[nx][ny] == '1')
            {
                dfs(nx, ny, grid, visited);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        int numberOfIslands = 0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == '1' && visited[i][j] == 0)
                {
                    numberOfIslands++;
                    dfs(i,j, grid, visited);
                }
            }
        }

        return numberOfIslands;
    }
};