class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int result = INT_MIN;

        unordered_set<char> st;

        int left = 0, right = 0;
        while(right < n)
        {
            if(st.find(s[right]) == st.end())
            {
                st.insert(s[right]);
                result = max(result, right - left + 1);
                right++;
            }
            else
            {
                st.erase(s[left]);
                left++;
            }
        }

        return result == INT_MIN ? 0 : result;
    }
};