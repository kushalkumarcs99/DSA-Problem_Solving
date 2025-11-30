class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int left = 0;
        int maxFreq = 0;
        int maxLen = 0;

        for (int right = 0; right < (int)s.size(); ++right) {
            freq[s[right] - 'A']++;
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            int windowLen = right - left + 1;

            // if more than k characters need to be changed, shrink from the left
            while (windowLen - maxFreq > k) {
                freq[s[left] - 'A']--;
                left++;
                windowLen = right - left + 1;
            }

            maxLen = max(maxLen, windowLen);
        }

        return maxLen;
    }
};
