class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int numsLength = nums.size();
        int result = INT_MIN;
        int maxProductTillHere = 1;

        for(int  i = 0;i<numsLength;i++)
        {
            maxProductTillHere *= nums[i];
            result = max(result, maxProductTillHere);
        }
        return result;
    }
};