class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        int i = 0;
        while(i < intervals.size())
        {
            int start = intervals[i][0];
            int end = intervals[i][1];

            while(i + 1 < intervals.size() && intervals[i+1][0] <= end)
            {
                end = max(end, intervals[i+1][1]);
                i++;
            }
            result.push_back({start, end});
            i++;
        }
        return result;
    }
};