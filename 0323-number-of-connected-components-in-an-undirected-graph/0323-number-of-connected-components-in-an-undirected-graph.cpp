class Solution {
public:
    int find(vector<int> &parent, int x) {
        if (parent[x] != x)
            parent[x] = find(parent, parent[x]); // path compression
        return parent[x];
    }

    int combine(vector<int> &parent, vector<int> &rank, int a, int b) {
        a = find(parent, a);
        b = find(parent, b);

        if (a == b) return 0;

        // union by rank
        if (rank[a] > rank[b]) {
            parent[b] = a;
        }
        else if (rank[b] > rank[a]) {
            parent[a] = b;
        }
        else {
            parent[b] = a; 
            rank[a]++;     // increase rank when equal
        }

        return 1;
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n), rank(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        int components = n;

        for (auto &e : edges) {
            components -= combine(parent, rank, e[0], e[1]);
        }

        return components;
    }
};
