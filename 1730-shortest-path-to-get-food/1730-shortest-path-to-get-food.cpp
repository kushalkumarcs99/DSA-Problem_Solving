class Solution {
public:
    int getFood(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> visited(n, vector<int>(m, 0));

        // Find start (*)
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '*') {
                    q.push({i, j});
                    visited[i][j] = 1;
                }
            }
        }

        int steps = 0;
        vector<pair<int,int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};

        while(!q.empty()) {
            int size = q.size();

            while(size--) {
                auto [x, y] = q.front();
                q.pop();

                for(auto &d : dirs) {
                    int nx = x + d.first;
                    int ny = y + d.second;

                    // ✅ boundary check first
                    if(nx < 0 || ny < 0 || nx >= n || ny >= m)
                        continue;

                    if(visited[nx][ny] || grid[nx][ny] == 'X')
                        continue;

                    // ✅ found food
                    if(grid[nx][ny] == '#')
                        return steps + 1;

                    visited[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }

            steps++; // level increment
        }

        return -1;
    }
};