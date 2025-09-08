class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> hash;  // stores frequency of chars
        int left = 0, result = 0;

        for (int right = 0; right < n; right++) {
            hash[s[right]]++;

            // if duplicate found, shrink window from left
            while (hash[s[right]] > 1) {
                hash[s[left]]--;
                left++;
            }

            // update result with current window size
            result = max(result, right - left + 1);
        }

        return result;
    }
};
