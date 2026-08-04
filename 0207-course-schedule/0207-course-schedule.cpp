class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        for(int i=0;i<n;i++)
        {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;

        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }

        int processed = 0;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            processed++;

            for(int neighbor : adj[node])
            {
                indegree[neighbor]--;
                if(indegree[neighbor]==0)
                {
                    q.push(neighbor);
                }
            }
        }
        return processed == numCourses;
    }
};