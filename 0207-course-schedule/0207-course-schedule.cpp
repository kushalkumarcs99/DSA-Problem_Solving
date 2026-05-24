class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<vector<int>> adjList(numCourses);
        vector<int> indegree(numCourses, 0);

        for(auto &prerequisite : prerequisites)
        {
            int node1 = prerequisite[0];
            int node2 = prerequisite[1];

            adjList[node1].push_back(node2);
            indegree[node2]++;
        }

        queue<int> q;

        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i] == 0)
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

            for(int next : adjList[node])
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