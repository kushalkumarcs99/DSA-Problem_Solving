class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_set<char> hash;

        int result = 0;
        int left = 0, right = 0;

        while(right < n)
        {
            if(hash.find(s[right]) == hash.end())
            {
                result = max(result, right - left + 1);
                hash.insert(s[right]);
                right++;
            }
            else
            {
                hash.erase(s[left]);
                left++;
            }
        }
        return result;
    }
};