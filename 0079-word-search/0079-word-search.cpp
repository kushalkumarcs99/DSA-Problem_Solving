class Solution {
public:

    bool dfs(int i, int j,
             vector<vector<char>>& board,
             vector<vector<int>>& visited,
             string& word,
             int id)
    {
        if(id == word.size())
        {
            return true;
        }

        int n = board.size();
        int m = board[0].size();

        if(i < 0 || j < 0 || i >= n || j >= m)
        {
            return false;
        }

        if(visited[i][j] || board[i][j] != word[id])
        {
            return false;
        }

        visited[i][j] = 1;

        vector<pair<int,int>> dirs =
        {
            {0,1},
            {0,-1},
            {1,0},
            {-1,0}
        };

        for(auto dir : dirs)
        {
            int nx = i + dir.first;
            int ny = j + dir.second;

            if(dfs(nx, ny, board, visited, word, id+1))
            {
                return true;
            }
        }

        visited[i][j] = 0;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word)
    {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> visited(n, vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(dfs(i, j, board, visited, word, 0))
                {
                    return true;
                }
            }
        }

        return false;
    }
};