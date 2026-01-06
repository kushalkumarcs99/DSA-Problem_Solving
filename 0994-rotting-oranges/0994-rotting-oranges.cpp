class Solution {
public:
    vector<pair<int,int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;

        // Step 1: Push all rotten oranges & count fresh ones
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2)
                    q.push({i, j});
                else if(grid[i][j] == 1)
                    fresh++;
            }
        }

        int minutes = 0;

        // Step 2: Multi-source BFS
        while(!q.empty() && fresh > 0) {
            int size = q.size();
            minutes++;

            while(size--) {
                auto [x, y] = q.front();
                q.pop();

                for(auto [dx, dy] : dirs) {
                    int i = x + dx;
                    int j = y + dy;

                    if(i >= 0 && i < n && j >= 0 && j < m &&
                       grid[i][j] == 1) {

                        grid[i][j] = 2;   // mark as rotten
                        fresh--;
                        q.push({i, j});
                    }
                }
            }
        }

        return fresh == 0 ? minutes : -1;
    }
};
