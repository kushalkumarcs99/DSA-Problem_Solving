class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();

        int left = 0, right = 0, numOfZeroes = 0, result = 0;

        while(right < n)
        {
            if(nums[right] == 0)
            {
                numOfZeroes++;
            }

            while(numOfZeroes == 2)
            {
                if(nums[left] == 0)
                {
                    numOfZeroes--;
                }
                left++;
            }

            result = max(result, right - left +  1);
            right++;
        }

        return result;
    }
};