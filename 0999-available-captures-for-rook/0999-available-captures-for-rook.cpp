class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {

        int rookRow, rookCol;

        // Find rook position
        for(int i = 0; i < 8; i++)
        {
            for(int j = 0; j < 8; j++)
            {
                if(board[i][j] == 'R')
                {
                    rookRow = i;
                    rookCol = j;
                }
            }
        }

        int captures = 0;

        vector<pair<int,int>> dirs = {
            {0,1},
            {1,0},
            {0,-1},
            {-1,0}
        };

        for(auto dir : dirs)
        {
            int x = rookRow;
            int y = rookCol;

            while(true)
            {
                x += dir.first;
                y += dir.second;

                // Boundary check
                if(x < 0 || y < 0 || x >= 8 || y >= 8)
                {
                    break;
                }

                // Bishop blocks path
                if(board[x][y] == 'B')
                {
                    break;
                }

                // Pawn captured
                if(board[x][y] == 'p')
                {
                    captures++;
                    break;
                }
            }
        }

        return captures;
    }
};