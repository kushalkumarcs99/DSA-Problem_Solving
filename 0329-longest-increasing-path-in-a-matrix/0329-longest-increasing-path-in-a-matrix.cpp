class Solution {
public:
    int m, n; // m = rows, n = cols
    vector<vector<int>> memo;
    const vector<pair<int,int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};

    int dfs(int i, int j, vector<vector<int>>& matrix) {
        if (memo[i][j] != 0) return memo[i][j];

        int best = 1;
        for (const auto &d : dirs) {
            int x = i + d.first;
            int y = j + d.second;
            if (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[i][j]) {
                best = max(best, 1 + dfs(x, y, matrix));
            }
        }
        memo[i][j] = best;
        return best;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        m = matrix.size();
        n = matrix[0].size();
        memo.assign(m, vector<int>(n, 0)); // initialize memo

        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = max(ans, dfs(i, j, matrix));
            }
        }
        return ans;
    }
};