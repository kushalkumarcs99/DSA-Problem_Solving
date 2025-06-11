#include<bits/stdc++.h>
class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int n = heights.size();
        vector<int> result;
        int maxTillHere = INT_MIN;
        for(int i=n-1;i>=0;i--)
        {
            if(i==n-1)
            {
                result.push_back(i);
                maxTillHere = heights[i];
            }
            else
            {
                if(heights[i] > heights[i+1] && heights[i] > maxTillHere)
                {
                    result.push_back(i);
                }
                maxTillHere = max(maxTillHere, heights[i]);
            }
        }
        reverse(result.begin(), result.end());
            return result;
    }
};