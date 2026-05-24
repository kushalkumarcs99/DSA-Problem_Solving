class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> hash;

        for(int i=0;i<n;i++)
        {
            hash[nums[i]]++;
        }

        priority_queue<pair<int, int>> pq;

        for(auto ele : hash)
        {
            pq.push({ele.second, ele.first});
        }

        vector<int> result;

        while(k--)
        {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};