class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int result = 0;
        int maxStockPrice = prices[n-1];
        for(int i=n-2;i>=0;i--)
        {
            int profit = maxStockPrice - prices[i];
            maxStockPrice = max(maxStockPrice, prices[i]);
            result = max(result, profit);
        }
        return result;
    }
};