class Solution {
public:
    void dfs(int i, vector<vector<int>>& isConnected, vector<bool>& visited)
    {
        visited[i] = true;
        for(int j=0;j<isConnected.size();j++)
        {
            if(i!=j and isConnected[i][j]==1 and visited[j]==false)
            {
                dfs(j,isConnected, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n,false);
        int provinces = 0;

        for(int i=0;i<n;i++)
        {
            if(visited[i]==false)
            {
                dfs(i, isConnected, visited);
                provinces++;
            }
        }
        return provinces;
    }
};