class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int numsLength = nums.size();
        int result = INT_MIN;
        int maxSubarraySumTillHere = 0;

        for(int i=0;i<numsLength;i++)
        {
            maxSubarraySumTillHere += nums[i];
            result = max(result, maxSubarraySumTillHere);
            if(maxSubarraySumTillHere < 0)
            {
                maxSubarraySumTillHere = 0;
            }
        }
        return result;
    }
};