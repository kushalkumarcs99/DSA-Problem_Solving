class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int stringLength = s.length();
        unordered_set<char> seen;
        int left = 0, right = 0;
        int longestSubstring = 0;

        while(right < stringLength)
        {
            if(seen.find(s[right]) == seen.end())
            {
                seen.insert(s[right]);
                longestSubstring = max(longestSubstring, right - left + 1);
                right++;
            }
            else
            {
                seen.erase(s[left]);
                left++;
            }
        }
        return longestSubstring;
    }
};