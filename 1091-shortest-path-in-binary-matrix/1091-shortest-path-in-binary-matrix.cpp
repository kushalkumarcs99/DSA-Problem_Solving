class Solution {
public:
    int shortestBFS(vector<vector<int>>& grid, vector<vector<int>>& visited) {
    int n = grid.size();
    int m = grid[0].size();

    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = 1;

    int steps = 1; // starting cell counts

    vector<pair<int, int>> dirs = {
        {1,0},{-1,0},{0,1},{0,-1},
        {1,1},{1,-1},{-1,1},{-1,-1}
    };

    while (!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; i++) {
            auto [x, y] = q.front();
            q.pop();

            // ✅ destination reached
            if (x == n-1 && y == m-1)
                return steps;

            for (auto dir : dirs) {
                int dx = x + dir.first;
                int dy = y + dir.second;

                if (dx >= 0 && dy >= 0 && dx < n && dy < m &&
                    grid[dx][dy] == 0 && !visited[dx][dy]) {
                    
                    visited[dx][dy] = 1;
                    q.push({dx, dy});
                }
            }
        }

        steps++; // ✅ increase level AFTER processing all nodes
    }

    return -1; // not reachable
}
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if (grid[0][0] == 1)
            return -1;
        vector<vector<int>> visited(n, vector<int>(m,0));
        int result = shortestBFS(grid, visited);

        return result;
    }
};