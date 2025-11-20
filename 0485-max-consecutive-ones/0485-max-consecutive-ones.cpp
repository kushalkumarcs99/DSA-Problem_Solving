class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int currentMaxOnes = 0;
        int result = 0;

        for(int i = 0;i<n;i++)
        {
            if(nums[i]==1)
            {
                currentMaxOnes++;
                result = max(result, currentMaxOnes);
            }
            else
            {
                currentMaxOnes = 0;
            }
        }
        return result;
    }
};