class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        int left = 0;
        long long currentSum = 0;
        long long maxSum = 0;
        unordered_map<int, int> hash;
        for (int right = 0; right < n; right++) {
            // Add new element
            currentSum += nums[right];
            hash[nums[right]]++;

            // Window reached size k
            if (right - left + 1 == k) {
                // Remove left element
                if(hash.size() == k)
                {
                    maxSum = max(maxSum, currentSum);
                }
                currentSum -= nums[left];
                hash[nums[left]]--;
                if (hash[nums[left]] == 0) {
                    hash.erase(nums[left]);
                }
                left++;
            }
        }

        return maxSum;
    }
};