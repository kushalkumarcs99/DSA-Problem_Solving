class Solution {
public:
    int f(int idx, vector<int>& cost, vector<int> &dp)
    {
        if(idx >= cost.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        int stepOne = cost[idx] + f(idx + 1, cost, dp);
        int stepTwo = cost[idx] + f(idx + 2, cost, dp);

        return dp[idx] = min(stepOne, stepTwo);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n,-1);
        int indexZero = f(0,cost,dp);
        int indexOne = f(1, cost,dp);

        return min(indexZero, indexOne);
    }
};