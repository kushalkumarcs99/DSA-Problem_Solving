class Solution {
public:
    void backTrack(int ind, vector<int>& candidates, vector<int>& temp,
               vector<vector<int>>& result, int target) {
    
    if (target == 0) {
        result.push_back(temp);
        return;
    }

    if (ind == candidates.size() || target < 0) return;

    // ✅ TAKE (stay at same index)
    temp.push_back(candidates[ind]);
    backTrack(ind, candidates, temp, result, target - candidates[ind]);
    temp.pop_back();

    // ✅ SKIP (move to next index)
    backTrack(ind + 1, candidates, temp, result, target);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> result;
        vector<int> temp;
        backTrack(0,candidates,temp, result, target);
        return result;
    }
};