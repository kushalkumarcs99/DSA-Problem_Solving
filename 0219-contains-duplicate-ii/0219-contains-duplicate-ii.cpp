class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp;

        for(int right = 0;right < n;right++)
        {
            if(mp.find(nums[right]) != mp.end())
            {
                if(abs(mp[nums[right]] - right) <= k)
                {
                    return true;
                }
            }
            mp[nums[right]] = right;
        }
        return false;
    }
};