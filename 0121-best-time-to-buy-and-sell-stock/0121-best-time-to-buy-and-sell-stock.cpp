class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int result = 0;
        int maxTillHere = prices[n-1];
        for(int i=n-2;i>=0;i--)
        {
            result = max(result, maxTillHere - prices[i]);
            maxTillHere = max(maxTillHere, prices[i]);
        }
        return result;
    }
};