class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        for(int i=0;i<n-1;i++)
        {
            if(intervals[i][1] > intervals[i+1][0])
            {
                return false;
            }
        }

        return true;
    }
};