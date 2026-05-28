class Solution {
public:
    vector<vector<int>> dp;
    bool isPalindrome(string &str, int left, int right)
    {
        if(left >= right) return 1;

        if(dp[left][right] != -1) return dp[left][right];

        if(str[left] == str[right]) return dp[left][right] = isPalindrome(str, left + 1, right - 1);

        return dp[left][right] = false;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        if(n == 1) return s;
        
        int maxLen = 0;
        string longest;
        dp = vector<vector<int>>(n, vector<int>(n, -1));

        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(isPalindrome(s,i,j))
                {
                    int len = j - i + 1;
                    if(len > maxLen)
                    {
                        maxLen = len;
                        longest = s.substr(i, len);
                    }
                }
            }
        }
        return longest;
    }
};