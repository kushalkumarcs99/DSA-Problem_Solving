class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& onPath) {
        visited[node] = true;
        onPath[node] = true;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, adj, visited, onPath)) return true;
            } else if (onPath[neighbor]) {
                // Cycle detected
                return true;
            }
        }

        onPath[node] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        // Build adjacency list
        for (const auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> onPath(numCourses, false);

        for (int i = 0; i < numCourses; ++i) {
            if (!visited[i]) {
                if (dfs(i, adj, visited, onPath)) return false;
            }
        }

        return true;
    }
};
