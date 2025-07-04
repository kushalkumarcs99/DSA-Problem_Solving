class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();

        if(n == 1 and nums[0] == target)
        {
            return  true;
        }

        if(n == 1 and nums[0] != target)
        {
            return false;
        }

        int left = 0, right = n - 1;
        while(left <= right)
        {
            int mid = left + ((right - left)/2);
            if(nums[mid] == target)
            return true;

            if(nums[left] == nums[mid] and nums[mid] == nums[right])
            {
                left++;
                right--;
                continue;
            }

            if(nums[left] <= nums[mid])
            {
                if(nums[left] <= target && target <= nums[mid])
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else
            {
                if(target >= nums[mid] && target <= nums[right])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }
        return false;
    }
};