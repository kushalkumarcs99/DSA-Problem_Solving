class Solution {
public:
    int LCSHelper(const string& text1, const string& text2,
                  int i, int j, vector<vector<int>>& memo)
    {
        // Base case: if any index goes out of range
        if (i < 0 || j < 0)
            return 0;

        // If already computed
        if (memo[i][j] != -1)
            return memo[i][j];

        // If characters match
        if (text1[i] == text2[j]) {
            return memo[i][j] = 1 + LCSHelper(text1, text2, i - 1, j - 1, memo);
        }

        // Otherwise, try both possibilities
        int skipText1 = LCSHelper(text1, text2, i - 1, j, memo);
        int skipText2 = LCSHelper(text1, text2, i, j - 1, memo);

        return memo[i][j] = max(skipText1, skipText2);
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        // Memo table sized exactly as indices 0...(n-1)
        vector<vector<int>> memo(n, vector<int>(m, -1));

        // Start from last indices
        return LCSHelper(text1, text2, n - 1, m - 1, memo);
    }
};
