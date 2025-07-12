class Solution {
public:
    vector<string> result;
    void backtrack(string path, int open, int close, int n) {
        if (path.length() == 2 * n) {
            result.push_back(path);
            return;
        }

        if (open < n)
            backtrack(path + "(", open + 1, close, n);

        if (close < open)
            backtrack(path + ")", open, close + 1, n);
    }
    vector<string> generateParenthesis(int n) {
        string path = "";
        backtrack(path, 0, 0, n);
        return result;
    }
};