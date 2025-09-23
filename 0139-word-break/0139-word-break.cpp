class Solution {
public:
    bool solve(int index, string &s, unordered_set<string> &dict, vector<int> &dp) {
        // ✅ Base case: reached end of string
        if (index == s.size()) return true;

        // ✅ Memoization check
        if (dp[index] != -1) return dp[index];

        string temp = "";
        // Try all substrings starting from index
        for (int i = index; i < s.size(); i++) {
            temp += s[i];
            if (dict.find(temp) != dict.end()) {
                // If word found and rest of string works → success
                if (solve(i + 1, s, dict, dp)) {
                    return dp[index] = true;
                }
            }
        }

        return dp[index] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end()); // ✅ faster than map
        vector<int> dp(s.size(), -1);  // ✅ dp[index] = can we break from here?
        return solve(0, s, dict, dp);
    }
};
