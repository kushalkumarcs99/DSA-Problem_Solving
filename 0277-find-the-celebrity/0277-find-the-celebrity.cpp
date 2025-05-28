/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        vector<vector<int>> familiar(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (knows(i, j)) {
                    if (i == j) continue;
                    familiar[i][j] = 1;
                }
            }
        }

        vector<int> indegree(n, 0);
        vector<int> outdegree(n, 0);

        // Calculate indegree and outdegree for each vertex
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (familiar[u][v] == 1) {
                    indegree[v]++;
                    outdegree[u]++;
                }
            }
        }

        for (int i = 0; i < n; i++) {
        if (indegree[i] == n - 1 && outdegree[i] == 0) {
            return i; // Found the node
        }
    }

    return -1; 
    }
};