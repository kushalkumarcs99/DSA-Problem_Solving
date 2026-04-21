class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int count = 0;
        for (int i = 0; i < n; i++) {
        // Odd length palindromes (single character center)
        for (int l = i, r = i; l >= 0 && r < n && s[l] == s[r]; l--, r++)
            count++;

        // Even length palindromes (center between two characters)
        for (int l = i, r = i + 1; l >= 0 && r < n && s[l] == s[r]; l--, r++)
            count++;
    }
    return count;
    }
};