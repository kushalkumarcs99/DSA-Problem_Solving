class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> result;
        unordered_map<int, int> hash;
        for(int i=n-1;i>=0;i--)
        {
            int temp = target - nums[i];
            if(hash.find(temp) != hash.end())
            {
                return {i, hash[temp]};
            }
            hash[nums[i]] = i;
        }
        return {};
    }
};