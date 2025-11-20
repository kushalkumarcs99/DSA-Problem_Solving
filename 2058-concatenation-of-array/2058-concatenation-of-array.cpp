class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;

        result = nums;
        int i = 0;

        while(i < n)
        {
            result.push_back(nums[i]);
            i++;
        }

        return result;
    }
};