class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = 0, result = 0, noOfZeroes = 0;

        while(right < n)
        {
            if(nums[right] == 0)
            {
                noOfZeroes++;
            }

            while(noOfZeroes == k+1)
            {
                if(nums[left] == 0)
                {
                    noOfZeroes--;
                }
                left++;
            }

            result = max(result, right - left + 1);
            right++;
        }

        return result;
    }
};