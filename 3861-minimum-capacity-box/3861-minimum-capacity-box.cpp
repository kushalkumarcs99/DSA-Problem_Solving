class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int n = capacity.size();

        int result = -1;

        for(int i=0;i<n;i++)
        {
            if(capacity[i] >= itemSize)
            {
                if(result == -1)
                result = i;
                if(result != -1 and capacity[result] > capacity[i])
                result = i;
            }
        }
        return result;
    }
};