class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0, right = 0;
        int result = 0;
        unordered_set<char> st;
        while(left <=right && right < n)
        {
            if(st.find(s[right])==st.end())
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
        
        return result;
    }
};