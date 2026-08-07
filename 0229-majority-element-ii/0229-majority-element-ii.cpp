class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> hash;
        vector<int> result;
        for(int num : nums)
        {
            hash[num]++;
        }
        for(auto ele : hash)
        {
            if(ele.second > floor(nums.size() / 3))
            result.push_back(ele.first);
        }
        return result;
    }
};