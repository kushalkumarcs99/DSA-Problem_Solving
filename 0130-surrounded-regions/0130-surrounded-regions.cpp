class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& board)
    {
        int n = board.size();
        int m = board[0].size();
        if(i >= n || j >= m || i < 0 || j < 0) return;
        if(board[i][j] != 'O') return;

        board[i][j] = '#';

        vector<pair<int, int>> directions = {{0,-1},{0,1},{1,0},{-1,0}};

        for(auto direction : directions)
        {
            int nx = i + direction.first;
            int ny = j + direction.second;

            dfs(nx, ny, board);
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        for(int i=0;i<n;i++)
        {
            if(board[i][0] == 'O')
            {
                dfs(i,0,board);
            }

            if(board[i][m-1] == 'O')
            {
                dfs(i,m-1,board);
            }
        }

        for(int j=0;j<m;j++)
        {
            if(board[0][j] == 'O')
            {
                dfs(0,j,board);
            }

            if(board[n-1][j] == 'O')
            {
                dfs(n-1,j,board);
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O')
                {
                    board[i][j] = 'X';
                }

                if(board[i][j] == '#')
                {
                    board[i][j] = 'O';
                }
            }
        }
    }
};