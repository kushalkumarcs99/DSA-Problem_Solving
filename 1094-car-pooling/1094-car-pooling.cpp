class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> timestamp(1001);

        for(auto trip : trips)
        {
            timestamp[trip[1]] += trip[0];
            timestamp[trip[2]] -= trip[0];
        }

        int usedCapacity = 0;
        for(int number : timestamp)
        {
            usedCapacity += number;
            if(usedCapacity > capacity)
            {
                return false;
            }
        }
        return true;
    }
};