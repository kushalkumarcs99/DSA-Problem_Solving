class Solution {
public:
    int robDPHelper(int i, vector<int>& nums, vector<int>& dp)
    {
        if(i >= nums.size()) return 0;
        if(dp[i]!= -1) return dp[i];

        int include = nums[i] + robDPHelper(i+2,nums,dp);
        int notInclude = robDPHelper(i+1, nums, dp);

        dp[i] = max(include, notInclude);
        return dp[i];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return robDPHelper(0, nums, dp);
    }
};
