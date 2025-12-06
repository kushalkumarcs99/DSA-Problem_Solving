class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pricesLength = prices.size();
        int bestStockPrice = prices[0];
        int result = 0;

        for(int i=1;i<pricesLength;i++)
        {
            int bestSellTillHere = prices[i] - bestStockPrice;
            result = max(result, bestSellTillHere);
            bestStockPrice = min(bestStockPrice, prices[i]);
        }

        return result;
    }
};