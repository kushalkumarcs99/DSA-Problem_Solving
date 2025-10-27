class Solution {
public:
    bool canPartitionHelper(int index, vector<int> &nums, int target)
    {
        if(target == 0)
        {
            return true;
        }
        if(index == 0)
        {
            return nums[0] == target;
        }
        //Exclude case
        bool notConsider = canPartitionHelper(index-1,nums, target);

        //Include case
        bool consider = false;
        if(nums[index] >= target)
        consider = canPartitionHelper(index-1,nums, target - nums[index]);
        return notConsider || consider;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int arraySum = 0;
        for(int element : nums)
        {
            arraySum += element;
        }
        if(arraySum % 2 != 0)
        {
            return false;
        }
        return canPartitionHelper(n-1,nums,arraySum/2);
    }
};