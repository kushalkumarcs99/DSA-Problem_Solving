class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int heightProfit = 0;
        int last = prices[n-1];
        for(int i = n-2;i>=0;i--)
        {
            int profit = last - prices[i];
            heightProfit = max(heightProfit, profit);
            last = max(last, prices[i]);
        }
        return heightProfit;
    }
};