class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int stringLength = s.length();
        unordered_map<char, int> hash;
        int left = 0, right = 0;
        int longestSubstring = 0;

        while (right < stringLength) {
            hash[s[right]]++;

            // shrink while more than 2 distinct characters
            while (hash.size() > 2) {
                hash[s[left]]--;
                if (hash[s[left]] == 0) {
                    hash.erase(s[left]);
                }
                left++;
            }

            // now window [left, right] has at most 2 distinct chars
            longestSubstring = max(longestSubstring, right - left + 1);
            right++;
        }

        return longestSubstring;
    }
};
