class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        int i = 0;
        while(i < n)
        {
            int start = intervals[i][0];
            int end = intervals[i][1];
            bool flag = true;
            while(flag)
            {
                if(i < n-1 and end >= intervals[i+1][0])
                {
                    end = max(end,intervals[i+1][1]);
                }
                else
                {
                    flag = false;
                    result.push_back({start,end});
                }
                i++;
            }
        }
        return result;
    }
};