class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> hash;

        vector<int> result(2);

        for(int i=0;i<n;i++)
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