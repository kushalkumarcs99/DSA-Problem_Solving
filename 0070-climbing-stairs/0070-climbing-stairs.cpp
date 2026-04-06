class Solution {
public:
    int f(int step, int n, vector<int> &dp)
    {
        if(step == n) return 1;
        if(step > n) return 0;
        if(dp[step] != -1) return dp[step];
        return dp[step] = f(step + 1, n,dp) + f(step + 2, n,dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return f(0,n,dp);
    }
};