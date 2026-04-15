class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int N = times.size();

        vector<vector<pair<int, int>>> graph(n + 1);

        for (auto& t : times) {
            int u = t[0], v = t[1], w = t[2];
            graph[u].push_back({v, w});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, k}); // {time, node}

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();

            if (time > dist[node])
                continue;

            for (auto& [adjNode, wt] : graph[node]) {
                if (time + wt < dist[adjNode]) {
                    dist[adjNode] = time + wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        int ans = 0;

        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX)
                return -1;
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};