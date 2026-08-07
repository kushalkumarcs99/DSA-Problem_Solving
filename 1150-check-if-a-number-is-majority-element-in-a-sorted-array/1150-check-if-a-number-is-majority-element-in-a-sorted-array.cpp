class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int firstIndex = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int lastIndex = upper_bound(nums.begin(), nums.end(), target) - nums.begin();

        return lastIndex - firstIndex > nums.size() / 2;
    }
};