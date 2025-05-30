class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while(left < right)
        {
            int mid = (left) + (right - left)/2;
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1])
            {
                return nums[mid];
            }
            if(nums[mid]==nums[mid-1])
            {
                if(mid % 2 == 0)
                {
                    right = mid;
                }
                else
                {
                    left = mid+1;
                }
            }
            else if(nums[mid]==nums[mid+1])
            {
                if(mid % 2 == 0)
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }
        return nums[left];
    }
};