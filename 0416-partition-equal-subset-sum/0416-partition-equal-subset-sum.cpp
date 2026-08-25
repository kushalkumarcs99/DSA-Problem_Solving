class Solution {
public:
    bool solve(int ind,vector<int>& nums, int target, vector<vector<int>>& dp)
    {
        if(ind == nums.size()){return false;}

        if(target == 0) return true;
        if(dp[ind][target] != -1) return dp[ind][target];
        int notTake = solve(ind+1,nums, target,dp);

        int take = false;
        if(nums[ind] <= target)
        {
            take = solve(ind+1,nums,target - nums[ind],dp);
        }

        return dp[ind][target] = notTake || take;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int total = accumulate(nums.begin(), nums.end(),0);

        if(total % 2 != 0) return false;
        int target = total / 2;
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return solve(0,nums,total / 2, dp);
    }
};