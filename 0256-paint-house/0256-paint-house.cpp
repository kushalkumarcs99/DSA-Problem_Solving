class Solution {
public:
    int f(int house, int lastPaint, vector<vector<int>>& costs, vector<vector<int>>& dp)
    {
        if(house == 0)
        {
            int mini = INT_MAX;
            for(int paint = 0;paint<3;paint++)
            {
                if(paint != lastPaint)
                {
                    mini = min(mini, costs[0][paint]);
                }
            }
            return mini;
        }
        if(dp[house][lastPaint] != -1) {return dp[house][lastPaint];}
        int mini = INT_MAX;

        for(int paint = 0; paint < 3;paint++)
        {
            if(paint != lastPaint)
            {
                int cost = costs[house][paint] + f(house - 1, paint, costs,dp);
                mini = min(mini, cost);
            }
        }
        return dp[house][lastPaint] = mini;
    }
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<vector<int>> dp(n, vector<int>(4,-1));
        return f(n-1,3,costs,dp);
    }
};