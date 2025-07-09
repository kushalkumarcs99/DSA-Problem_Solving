class Solution {
public:
    vector<vector<int>> result;
    void subsetsHelper(int ind,vector<int>& nums, vector<int>& temp)
    {
        if(ind == nums.size())
        {
            result.push_back(temp);
            return;
        }
        //Exclude
        subsetsHelper(ind+1,nums,temp);

        //Include
        temp.push_back(nums[ind]);
        subsetsHelper(ind+1,nums,temp);

        //Backtrack
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        subsetsHelper(0,nums,temp);
        return result;
    }
};