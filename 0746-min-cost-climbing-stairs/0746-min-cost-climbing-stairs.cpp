class Solution {
public:
    int minCostClimbiingStairs(int ind, vector<int>& cost, vector<int>& dp) {
        if (ind >= cost.size()) {
            return 0;
        }
        if(dp[ind]!=-1) return dp[ind];
        int include = cost[ind] + min(minCostClimbiingStairs(ind + 1, cost, dp),
                                      minCostClimbiingStairs(ind + 2, cost, dp));

        return dp[ind] = include;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), -1);
        int result = min(minCostClimbiingStairs(0, cost, dp),
                         minCostClimbiingStairs(1, cost, dp));

        return result;
    }
};