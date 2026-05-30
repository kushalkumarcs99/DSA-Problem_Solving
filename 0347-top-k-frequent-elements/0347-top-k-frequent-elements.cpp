class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;

        for(int i=0;i<n;i++)
        {
            freq[nums[i]]++;
        }

        priority_queue<pair<int, int>> pq;

        for(auto ele : freq)
        {
            pq.push({ele.second, ele.first});
        }

        vector<int> ans;

        while(k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;

    }
};