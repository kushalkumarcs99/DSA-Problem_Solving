class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==1 || n==0) return n;
        set<int> st(nums.begin(), nums.end());

        int longest = 1;
        int currentLongest = 1;
        for (int num : st) {
            // start only if it's the beginning of a sequence
            if (st.find(num + 1) != st.end()) {
                currentLongest++;
                longest = max(longest, currentLongest);
            }
            else
            {
                currentLongest = 1;
            }
        }

        return longest;
    }
};