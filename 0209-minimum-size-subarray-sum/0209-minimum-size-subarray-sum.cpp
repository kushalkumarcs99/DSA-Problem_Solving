class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        int left = 0;
        int right = 0;
        int currentSum = 0;
        int result = INT_MAX;

        while (right < n) {
            currentSum += nums[right];

            while (currentSum >= target) {
                result = min(result, right - left + 1);

                currentSum -= nums[left];
                left++;
            }

            right++;
        }

        return result == INT_MAX ? 0 : result;
    }
};