class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        int currentCount = 0;
        for(int i=0;i<n;i++)
        {
            if(nums[i] == 1)
            {
                currentCount++;
                result = max(result, currentCount);
            }
            else
            {
                currentCount = 0;
            }
        }
        return result;
    }
};