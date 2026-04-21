class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        queue<tuple<int,int,int>> q; // x, y, remaining k
        q.push({0, 0, k});

        vector<vector<vector<bool>>> visited(n, 
            vector<vector<bool>>(m, vector<bool>(k+1, false)));

        visited[0][0][k] = true;

        int steps = 0;

        vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

        while(!q.empty()) {
            int size = q.size();

            while(size--) {
                auto [x, y, rem] = q.front();
                q.pop();

                if(x == n-1 && y == m-1)
                    return steps;

                for(auto& d : dirs) {
                    int nx = x + d.first;
                    int ny = y + d.second;

                    if(nx>=0 && ny>=0 && nx<n && ny<m) {
                        int newRem = rem - grid[nx][ny];

                        if(newRem >= 0 && !visited[nx][ny][newRem]) {
                            visited[nx][ny][newRem] = true;
                            q.push({nx, ny, newRem});
                        }
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};