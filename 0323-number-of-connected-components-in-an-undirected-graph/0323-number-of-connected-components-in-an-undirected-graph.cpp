class Solution {
public:
    void dfs(int node, vector<int>& vis, vector<vector<int>>& adj) {
        vis[node] = 1;
        for (int neigh : adj[node]) {
            if (!vis[neigh]) {
                dfs(neigh, vis, adj);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        
        // Build adjacency list
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<int> vis(n, 0);
        int components = 0;
        
        // Count connected components
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                components++;
                dfs(i, vis, adj);
            }
        }
        
        return components;
    }
};