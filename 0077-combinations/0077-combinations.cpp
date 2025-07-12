class Solution {
public:
    int n,k;
    void backtrack(int start, vector<int>& temp, vector<vector<int>>& result)
    {
        if(temp.size() == k)
        {
            result.push_back(temp);
            return;
        }

        if(start > n) return;
        temp.push_back(start);
        backtrack(start+1, temp, result);
        temp.pop_back();
        backtrack(start+1, temp, result);
    }
    vector<vector<int>> combine(int n, int k) {
        this->n = n;
        this->k = k;
        vector<vector<int>> result;
        vector<int> temp;
        backtrack(1,temp,result);
        return result;
    }
};