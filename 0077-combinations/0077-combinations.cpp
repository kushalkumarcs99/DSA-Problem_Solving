class Solution {
public:
    int n,k;
    void backtrack(int firstNum, vector<vector<int>>& result, vector<int>& current)
    {
        if(current.size() == k)
        {
            result.push_back(current);
            return;
        }

        for(int num = firstNum; num <= n; num++)
        {
            current.push_back(num);
            backtrack(num+1, result, current);
            current.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        this->n = n;
        this->k = k;
        vector<vector<int>> result;
        vector<int> current;
        backtrack(1,result, current);
        return result;
    }
};