class Solution {
public:
    int robHelper(int ind, vector<int>& nums, vector<int>& dp)
    {
        if(ind >= nums.size()) {return 0;}

        if(dp[ind] != -1) return dp[ind];
        int include;
        if(ind <= nums.size()-1)
        {
            include = nums[ind] + robHelper(ind+2, nums, dp);
        }

        int exclude = 0 + robHelper(ind+1, nums, dp);

        return dp[ind] = max(include, exclude);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);

        int result = robHelper(0,nums,dp);

        return result;
    }
};