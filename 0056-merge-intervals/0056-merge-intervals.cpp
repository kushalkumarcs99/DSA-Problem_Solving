class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // Step 1: Sort intervals
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;

        // Step 2: Start with first interval
        result.push_back(intervals[0]);

        for(int i = 1; i < n; i++) {
            vector<int>& last = result.back();

            // Overlap case
            if(intervals[i][0] <= last[1]) {
                last[1] = max(last[1], intervals[i][1]);
            } 
            else {
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};