class Solution {
public:
    int minKnightMoves(int x, int y) {
        x = abs(x);
        y = abs(y);

        vector<vector<bool>> visited(605, vector<bool>(605, false));
        queue<pair<int,int>> q;

        q.push({0, 0});
        visited[300][300] = true;

        int moves = 0;

        int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
        int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [cx, cy] = q.front();
                q.pop();

                if (cx == x && cy == y) return moves;

                for (int i = 0; i < 8; i++) {
                    int nx = cx + dx[i];
                    int ny = cy + dy[i];

                    int ox = nx + 300;
                    int oy = ny + 300;

                    if (ox >= 0 && oy >= 0 && ox < 605 && oy < 605 && !visited[ox][oy]) {
                        visited[ox][oy] = true;
                        q.push({nx, ny});
                    }
                }
            }
            moves++;
        }

        return -1;
    }
};
