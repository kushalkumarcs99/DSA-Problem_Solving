class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int result = INT_MAX;

        int left = 0;
        int sum = 0;
        for(int right = 0;right<n;right++)
        {
            sum += nums[right];
            while(sum >= target)
            {
                result = min(result, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        return result == INT_MAX ? 0 : result;
    }
};