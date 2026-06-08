/**
 * @param {number[][]} intervals
 * @return {boolean}
 */
var canAttendMeetings = function(intervals) {
    let n = intervals.length;
    intervals.sort();

    for(let i=0;i<n-1;i++)
    {
        if(intervals[i][1] > intervals[i+1][0])
        {
            return false;
        }
    }

    return true;
};