class Solution {
public:
    void backTrackSubSet(int ind, vector<int>& nums,
                         vector<vector<int>>& result, vector<int>& temp) {
        if (ind == nums.size()) {
            result.push_back(temp);
            return;
        }
        // include
        temp.push_back(nums[ind]);
        backTrackSubSet(ind + 1, nums, result, temp);

        // exclude
        temp.pop_back();
        backTrackSubSet(ind + 1, nums, result, temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> result;
        vector<int> temp;
        backTrackSubSet(0, nums, result, temp);
        return result;
    }
};