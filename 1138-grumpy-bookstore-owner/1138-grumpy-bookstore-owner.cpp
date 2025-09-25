class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        
        int baseSatisfied = 0; // customers always satisfied
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0) {
                baseSatisfied += customers[i];
                customers[i] = 0; // mark as already counted
            }
        }

        // Sliding window: max extra customers that can be satisfied
        int extra = 0, maxExtra = 0;
        for (int i = 0; i < n; i++) {
            extra += customers[i];
            if (i >= minutes) {
                extra -= customers[i - minutes];
            }
            maxExtra = max(maxExtra, extra);
        }

        return baseSatisfied + maxExtra;
    }
};
