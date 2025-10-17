#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0) return 0;
        // memo[i] = number of ways to decode substring s[i..end-1], -1 means not computed
        vector<int> memo(n, -1);
        return dfs(0, s, memo);
    }

private:
    int dfs(int i, const string &s, vector<int> &memo) {
        int n = s.size();
        if (i == n) return 1;            // reached end -> one valid decoding
        if (s[i] == '0') return 0;       // cannot decode a leading '0'
        if (memo[i] != -1) return memo[i];

        int ways = 0;

        // take one digit
        ways += dfs(i + 1, s, memo);

        // take two digits if valid
        if (i + 1 < n) {
            int two = (s[i] - '0') * 10 + (s[i + 1] - '0');
            if (two >= 10 && two <= 26)
                ways += dfs(i + 2, s, memo);
        }

        memo[i] = ways;
        return ways;
    }
};
