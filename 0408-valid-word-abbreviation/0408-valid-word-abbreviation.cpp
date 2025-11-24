class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int n = word.size();
        int m = abbr.size();

        int i = 0;          // index in abbr
        int idx = 0;        // index in word

        while (i < m && idx < n) {
            if (isdigit(abbr[i])) {
                // number cannot start with '0'
                if (abbr[i] == '0') return false;

                int start = i;
                int num = 0;

                while (i < m && isdigit(abbr[i])) {
                    num = num * 10 + (abbr[i] - '0');
                    i++;
                }

                idx += num; // skip `num` chars in word
            } else {
                // letter must match exactly
                if (idx >= n || word[idx] != abbr[i]) return false;
                idx++;
                i++;
            }
        }

        // both must be fully consumed for a valid abbreviation
        return i == m && idx == n;
    }
};
