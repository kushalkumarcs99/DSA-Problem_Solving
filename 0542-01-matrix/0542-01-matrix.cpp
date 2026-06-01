class Solution {
public:
    int m,n;
    bool isValid(int row, int col)
    {
        return 0 <= row && row < n && 0 <= col && col < m;
    }
    vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        n = mat.size();
        m = mat[0].size();

        vector<vector<int>> matrix(n, vector<int>(m,0));
        vector<vector<bool>> seen(n, vector<bool>(m, false));
        queue<vector<int>> queue;

        for(int row=0;row<n;row++)
        {
            for(int col=0;col<m;col++)
            {
                matrix[row][col] = mat[row][col];
                if(matrix[row][col] == 0)
                {
                    queue.push({row, col, 0});
                    seen[row][col] = true;
                }
            }
        }

        while(!queue.empty())
        {
            vector<int> curr = queue.front();
            queue.pop();

            int row = curr[0], col = curr[1], steps = curr[2];

            for(vector<int>& direction : directions)
            {
                int nextRow = row + direction[0], nextCol = col + direction[1];

                if(isValid(nextRow, nextCol) && !seen[nextRow][nextCol])
                {
                    seen[nextRow][nextCol] = true;
                    queue.push({nextRow, nextCol, steps + 1});
                    matrix[nextRow][nextCol] = steps + 1;
                }
            }
        }

        return matrix;
    }
};