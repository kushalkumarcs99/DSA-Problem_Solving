class Solution {
public:
    int minRemovals(vector<int>& nums, int target) {
        int totalXOR = 0;
        for (int num : nums) totalXOR ^= num;

        int K = totalXOR ^ target;

        unordered_map<int, int> dp;
        dp[0] = 0;

        for (int num : nums) {
            auto new_dp = dp;

            for (auto &[x, cnt] : dp) {
                int nx = x ^ num;

                if (!new_dp.count(nx)) {
                    new_dp[nx] = cnt + 1;
                } else {
                    new_dp[nx] = min(new_dp[nx], cnt + 1);
                }
            }

            dp = new_dp;
        }

        return dp.count(K) ? dp[K] : -1;
    }
};