class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> result(2);
        unordered_map<int, int> hash;

        for(int i=0;i<n;i++)
        {
            int diff = target - nums[i];
            if(hash.find(diff) != hash.end())
            {
                return {hash[diff],i};
            }

            hash[nums[i]] = i;
        }
        return result;
    }
};