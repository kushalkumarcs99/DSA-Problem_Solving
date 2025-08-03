class Solution {
public:
    void dfs(vector<vector<char>>& board, int row, int col)
{
    int rows = board.size();
    int cols = board[0].size();

    if(row < 0 || row >= rows || col < 0 || col >= cols || board[row][col] != 'O') return;

    board[row][col] = 'T';

    dfs(board, row+1, col);   // down
    dfs(board, row-1, col);   // up
    dfs(board, row, col+1);   // right
    dfs(board, row, col-1);   // left
}
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        if(rows==0 || cols == 0) return;

        //Mark baorder 'O' & connected ones
        for(int i=0;i<rows;i++)
        {
            dfs(board,i,0);
            dfs(board,i,cols-1);
        }

        for(int j=0;j<cols;j++)
        {
            dfs(board,0,j);
            dfs(board,rows-1,j);
        }

        //Flip all remaining 'O" to 'X' & 'T' back to 'O'

        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(board[i][j] == 'O')
                board[i][j] = 'X';
                else if(board[i][j] == 'T')
                board[i][j] = 'O';
            }
        }
    }
};