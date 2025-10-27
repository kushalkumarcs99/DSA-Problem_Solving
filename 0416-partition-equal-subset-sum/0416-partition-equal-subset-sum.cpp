class Solution {
public:
    int n;
    vector<vector<int>> memo; // -1 unknown, 0 false, 1 true

    bool canPartitionHelper(int index, const vector<int> &nums, int target) {
        if (target == 0) return true;
        if (index == 0) return nums[0] == target;
        int &m = memo[index][target];
        if (m != -1) return m == 1;

        // Exclude
        bool notConsider = canPartitionHelper(index - 1, nums, target);

        // Include (only if nums[index] <= target)
        bool consider = false;
        if (nums[index] <= target)
            consider = canPartitionHelper(index - 1, nums, target - nums[index]);

        return m = (notConsider || consider) ? 1 : 0;
    }

    bool canPartition(vector<int>& nums) {
        n = nums.size();
        int sum = 0;
        for (int x : nums) sum += x;
        if (sum % 2 != 0) return false;
        int target = sum / 2;
        memo.assign(n, vector<int>(target + 1, -1));
        return canPartitionHelper(n - 1, nums, target);
    }
};
