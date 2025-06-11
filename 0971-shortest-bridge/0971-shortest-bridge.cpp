class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& visited, 
    queue<pair<int,int>>& q, vector<vector<int>>& dirs)
    {
        if(row >= grid.size() || row < 0 || col >= grid[0].size() || col < 0 ||
        visited[row][col] || grid[row][col]==0)
        return;

        visited[row][col] = true;
        q.push({row,col});

        for(auto& dir : dirs)
        {
            dfs(row+dir[0], col+dir[1], grid, visited,q,dirs);
        }

    }
    int shortestBridge(vector<vector<int>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        vector<vector<bool>> visited(rows,vector<bool>(columns,false));
        vector<vector<int>> dirs={{1,0},{-1,0},{0,1},{0,-1}};
        queue<pair<int,int>> q;
        bool found = false;
        for(int row=0;row<rows;row++)
        {
            for(int column=0;column<columns;column++)
            {
                if(grid[row][column]==1 && !visited[row][column])
                {
                    dfs(row,column,grid,visited,q,dirs);
                    found = true;
                    break;
                }
            }
            if(found) break;
        }
        int step = 0;
        while(!q.empty())
        {
            int size = q.size();
            while(size-- > 0)
            {
                auto cur = q.front();
                q.pop();

                for(auto& dir : dirs)
                {
                    int i = cur.first + dir[0];
                    int j = cur.second + dir[1];

                    if(i>=0 && j>=0 && i<rows && j<columns && !visited[i][j])
                    {
                        if(grid[i][j] == 1)
                        {
                            return step;
                        }
                        q.push({i,j});
                        visited[i][j] = true;
                    }
                }
            }
            step++;
        }
        return -1;
    }
};