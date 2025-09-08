class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> hash;

        for(int i=0;i<n;i++)
        {
            hash[nums[i]]++;
        }
        vector<pair<int,int>> freq(hash.begin(), hash.end());

        sort(freq.begin(), freq.end(), [](auto &a, auto &b) {
        if (a.second == b.second) 
            return a.first < b.first; // (optional: sort by key if freq equal)
        return a.second > b.second;   // descending order of frequency
    });

        vector<int> result;
        int i = 0;
        while(i < k)
        {
            result.push_back(freq[i].first);
            i++;
        }
        return result;
    }
};