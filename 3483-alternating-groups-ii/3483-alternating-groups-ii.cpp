class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        long long result = 0;

        // Create doubled array to simulate circular wrap
        vector<int> doubled(2 * n);
        for (int i = 0; i < 2 * n; i++) {
            doubled[i] = colors[i % n];
        }

        int streak = 1;  // length of current alternating streak

        for (int i = 1; i < 2 * n; i++) {
            if (doubled[i] != doubled[i - 1]) {
                streak++;
            } else {
                streak = 1;
            }

            // If streak length >= k, we can form a group ending here
            if (streak >= k && i - (k - 1) < n) {
                result++;
            }
        }

        return (int)result;
    }
};
