class Solution {
public:
    int dp[1001][1001];
    bool isPalindrome(const std::string &str, int left, int right) {
    if(left >= right) return 1;

    if(dp[left][right] != -1) return dp[left][right];

    if(str[left] == str[right]) return dp[left][right] = isPalindrome(str,left+1,right-1);

    return dp[left][right] = false;
}
    int countSubstrings(string s) {
        int n = s.length();
    int maxLen = 0;
    int longest = 0;
    memset(dp,-1,sizeof(dp));

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (isPalindrome(s, i, j)) {
                longest++;
            }
        }
    }
    return longest;
    }
};