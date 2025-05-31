class Solution {
public:
    void dfs(int row, int column, vector<vector<char>>& grid,
             vector<vector<bool>>& visited) {
        visited[row][column] = true;
        int rows = grid.size();
        int columns = grid[0].size();

        // Explore 4 directions (up, down, left, right)
        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};

        for (int i = 0; i < 4; ++i) {
            int nr = row + dr[i];
            int nc = column + dc[i];
            if (nr >= 0 && nr < rows && nc >= 0 && nc < columns &&
                !visited[nr][nc] && grid[nr][nc] == '1') {
                dfs(nr, nc, grid, visited);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(columns, false));
        int numberOfIslands = 0;

        for (int row = 0; row < rows; row++) {
            for (int column = 0; column < columns; column++) {
                if (!visited[row][column] && grid[row][column] == '1') {
                    numberOfIslands++;
                    dfs(row, column, grid, visited);
                }
            }
        }
        return numberOfIslands;
    }
};
