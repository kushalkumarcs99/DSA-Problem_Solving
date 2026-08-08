class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maximumProfit = 0;

        int maxStockPrice = prices[n-1];

        for(int i=n-2;i>=0;i--)
        {
            int currentProfit = maxStockPrice - prices[i];
            maximumProfit = max(maximumProfit, currentProfit);
            maxStockPrice = max(maxStockPrice, prices[i]);
        }

        return maximumProfit;
    }
};