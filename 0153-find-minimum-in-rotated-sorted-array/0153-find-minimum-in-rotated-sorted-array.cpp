class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        if(n == 1)
        {
            return nums[0];
        }

        int minEle = INT_MAX;
        int left = 0, right = n-1;

        while(left <= right)
        {
            int mid = left + ((right - left) / 2);
            if(nums[left] <= nums[mid])
            {   
                minEle = min(minEle, nums[left]);
                left = mid + 1;
            }
            else
            {
                minEle = min(minEle, nums[mid]);
                right = mid - 1;
            }
        }
        return minEle;
    }
};