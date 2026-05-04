class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        int count = 0;

        for (int i = 0; i < n; i++) {
            // Initialize sum for current subarray
            int sum = 0;

            // Traverse all possible end indices from start
            for (int j = i; j < n; j++) {
                // Add current element to sum
                sum += nums[j];

                // If sum equals k, increment count
                if (sum == k) {
                    count++;
                }
            }
        }

        return count;
    }
};