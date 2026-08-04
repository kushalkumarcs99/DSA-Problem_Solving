class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses,0);
        for(auto &prerequisite : prerequisites)
        {
            int u = prerequisite[0];
            int v = prerequisite[1];

            adj[v].push_back(u);
            inDegree[u]++;
        }

        queue<int> q;

        for(int i=0;i<numCourses;i++){
            if(inDegree[i]==0)
            {
                q.push(i);
            }
        }

        vector<int> topo;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            topo.push_back(node);

            for(int neighbor : adj[node])
            {
                inDegree[neighbor]--;
                if(inDegree[neighbor]==0)
                {
                    q.push(neighbor);
                }
            }
        }

        return topo.size() == numCourses ? topo : vector<int>{};
    }
};