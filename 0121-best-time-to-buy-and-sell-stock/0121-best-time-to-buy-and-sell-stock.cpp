class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;
        int maxStockPrice = prices[n-1];

        for(int i=n-2;i>=0;i--)
        {
            maxProfit = max(maxProfit, maxStockPrice - prices[i]);
            maxStockPrice = max(maxStockPrice, prices[i]);
        }
        return maxProfit;
    }
};