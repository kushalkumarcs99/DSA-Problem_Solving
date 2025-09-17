class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n = nums.size();

        if (n % k != 0) return false;

        unordered_map<int, int> hash;

        for(int i=0;i<n;i++)
        {
            hash[nums[i]]++;
        }

        int groups = n / k;

        // Condition 2: no element should appear more than number of groups
        for (auto& [num, count] : hash) {
            if (count > groups) {
                return false;
            }
        }

        return true;
    }
};