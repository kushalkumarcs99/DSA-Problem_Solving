class Solution {
public:
    void subsetsHelper(int ind, vector<int>& nums, vector<int>& temp, vector<vector<int>>& result)
    {
        if(ind == nums.size())
        {
            result.push_back(temp);
            return;
        }

        temp.push_back(nums[ind]);
        subsetsHelper(ind+1, nums, temp, result);
        temp.pop_back();
        subsetsHelper(ind+1, nums, temp, result);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        vector<int> temp;
        subsetsHelper(0, nums, temp, result);
        return result;
    }
};