class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int n = s.size();
        unordered_map<char, int> hash;

        int left = 0, right = 0;
        int longestSubstring = 0;

        while(right < n)
        {
            hash[s[right]]++;

            while(hash.size() > k)
            {
                hash[s[left]]--;
                if(hash[s[left]] == 0)
                {
                    hash.erase(s[left]);
                }
                left++;
            }

            longestSubstring = max(longestSubstring, right - left + 1);
            right++;
        }
        return longestSubstring;
    }
};