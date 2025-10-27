class Solution {
public:
    unordered_map<int,int> memo;

    int solveMinDays(int n) {
        if (n <= 1) return n;              // dp[0]=0, dp[1]=1
        if(memo.find(n) != memo.end()) return memo[n];

        int x = n%2 + solveMinDays(n/2);
        int y = n%3 + solveMinDays(n/3);

        return memo[n] = 1 + min(x,y);
    }

    int minDays(int n) {
        memo.clear();
        return solveMinDays(n);
    }
};