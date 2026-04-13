class Solution {
public:
    int countGoodSubstrings(string s) {
        int l = 0;
        int cnt = 0;
        unordered_map<char, int> m;

        for (int r = 0; r < s.size(); r++) {
            // If window size exceeds 3, shrink from left
            if (r - l + 1 > 3) {
                m[s[l]]--;           // remove left character
                if (m[s[l]] == 0) {
                    m.erase(s[l]);  // erase if frequency becomes 0
                }
                l++;               // move left pointer
            }

            m[s[r]]++;            // add current character

            // If all 3 characters are unique
            if (m.size() == 3) {
                cnt++;
            }
        }

        return cnt;

    }
};