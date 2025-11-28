class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> comb;
        backtrack(0, candidates, target, comb, result);
        return result;
    }

private:
    void backtrack(int start, vector<int>& candidates, int target,
                   vector<int>& comb, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(comb);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            // 🔴 Skip duplicates at the same recursion depth
            if (i > start && candidates[i] == candidates[i - 1]) continue;

            // 🔧 Small optimization: numbers are sorted
            if (candidates[i] > target) break;

            comb.push_back(candidates[i]);
            backtrack(i + 1, candidates, target - candidates[i], comb, result);
            comb.pop_back();
        }
    }
};
