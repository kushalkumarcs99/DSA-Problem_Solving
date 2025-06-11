class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> dirs = {{-1,0},{1,0},{0,1},{0,-1}};
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        queue<pair<int,int>> q;

        // Put all land cells into queue
        for(int row = 0; row < rows; row++) {
            for(int col = 0; col < cols; col++) {
                if(grid[row][col] == 1) {
                    q.push({row, col});
                    visited[row][col] = true;
                }
            }
        }

        // Edge case: if there's no water or no land
        if(q.empty() || q.size() == rows * cols)
            return -1;

        int distance = -1;

        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                auto [row, col] = q.front(); q.pop();
                for(auto& dir : dirs) {
                    int i = row + dir[0];
                    int j = col + dir[1];

                    if(i >= 0 && i < rows && j >= 0 && j < cols && !visited[i][j] && grid[i][j] == 0) {
                        visited[i][j] = true;
                        q.push({i, j});
                    }
                }
            }
            distance++;
        }
        return distance;
    }
};
