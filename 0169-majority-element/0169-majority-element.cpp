class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> hash;

        for(int num : nums)
        {
            hash[num]++;
        }
        for(auto ele : hash)
        {
            if(ele.second > floor(nums.size() / 2))
            return ele.first;
        }
        return 0;
    }
};