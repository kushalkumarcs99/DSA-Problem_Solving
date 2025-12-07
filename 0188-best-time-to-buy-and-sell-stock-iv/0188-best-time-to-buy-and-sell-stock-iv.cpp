class Solution {
public:
    int fun(int ind, int buy, int cap,
            vector<int>& prices, int n,
            vector<vector<vector<int>>>& dp) {
        
        if (ind == n || cap == 0) return 0;

        if (dp[ind][buy][cap] != -1) return dp[ind][buy][cap];

        int profit = 0;
        if (buy) {
            profit = max(
                -prices[ind] + fun(ind + 1, 0, cap, prices, n, dp), // buy
                0 + fun(ind + 1, 1, cap, prices, n, dp)             // skip
            );
        } else {
            profit = max(
                prices[ind] + fun(ind + 1, 1, cap - 1, prices, n, dp), // sell
                0 + fun(ind + 1, 0, cap, prices, n, dp)                // skip
            );
        }

        return dp[ind][buy][cap] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int cap = k;
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(cap + 1, -1))
        );

        return fun(0, 1, cap, prices, n, dp);
    }
};
