class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for(auto &p : prerequisites)
        {
            int node1 = p[0];
            int node2 = p[1];

            adj[node1].push_back(node2);
            indegree[node2]++;
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

            for(int next : adj[node])
            {
                indegree[next]--;
                if(indegree[next] == 0)
                {
                    q.push(next);
                }
            }
        }
        return processed == numCourses;
    }
};