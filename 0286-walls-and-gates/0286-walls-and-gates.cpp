class Solution {
public:
    int wall = -1;
    int gate = 0;
    int emptyRoom = 2147483647;
    vector<pair<int, int>> dirs={{-1,0},{1,0},{0,-1},{0,1}};
    void wallsAndGates(vector<vector<int>>& rooms) {
        int n = rooms.size();
        int m = rooms[0].size();

        queue<pair<int, int>> q;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(rooms[i][j] == gate)
                {
                    q.push({i,j});
                }
            }
        }

        int distance = 0;
        while(!q.empty())
        {
            int size = q.size();
            distance++;

            while(size--)
            {
                auto [x,y] = q.front();
                q.pop();

                for(auto [dx,dy] : dirs)
                {
                    int i = x + dx;
                    int j = y + dy;

                    if(i >=0 && i<n && j>=0 && j<m && rooms[i][j]==emptyRoom)
                    {
                        rooms[i][j] = distance;
                        q.push({i,j});
                    }
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<rooms[i][j];
            }
            cout<<endl;
        }

    }
};