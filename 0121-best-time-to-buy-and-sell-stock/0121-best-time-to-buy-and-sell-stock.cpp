class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int result = 0;

        int currentMax = prices[n-1];

        for(int i=n-2;i>=0;i--)
        {
            int temp = currentMax - prices[i];
            result = max(result, temp);
            currentMax = max(currentMax, prices[i]);
        }

        return result;
    }
};