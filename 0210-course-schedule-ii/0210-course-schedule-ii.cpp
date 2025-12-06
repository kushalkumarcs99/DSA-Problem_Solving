class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        // build graph: b -> a
        for (auto &p : prerequisites) {
            int course = p[0];      // to take
            int prereq = p[1];      // must take before
            adj[prereq].push_back(course); // edge: prereq -> course
            indegree[course]++;
        }

        queue<int> q;

        // push all nodes with indegree 0
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topoOrder;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            topoOrder.push_back(node);

            for (int next : adj[node]) {
                indegree[next]--;
                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        // if we processed all courses, no cycle
        if (topoOrder.size() == numCourses) 
            return topoOrder;

        // cycle exists → cannot finish all courses
        return {};
    }
};
