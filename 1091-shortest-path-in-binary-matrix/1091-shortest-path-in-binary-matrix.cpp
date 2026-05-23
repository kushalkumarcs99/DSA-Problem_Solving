class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if (grid[0][0] == 1)
            return -1;

        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1},  {0, -1},
                                       {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        q.push({0, 0});
        vis[0][0] = 1;
        int length = 1;
        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                auto [nx, ny] = q.front();
                q.pop();

                if (nx == n - 1 && ny == m - 1)
                    return length;
                
                for(auto dir : dirs)
                {
                    int dx = nx + dir.first;
                    int dy = ny + dir.second;

                    if(dx >= 0 && dy >= 0 && dx < n && dy < m && grid[dx][dy] == 0 && !vis[dx][dy])
                    {
                        vis[dx][dy] = 1;
                        q.push({dx, dy});
                    }
                }
            }
            length++;
        }
        return -1;
    }
};