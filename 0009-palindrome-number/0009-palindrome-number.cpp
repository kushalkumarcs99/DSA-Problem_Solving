class Solution {
public:
    bool isPalindrome(string ans)
    {
        int i = 0, j = ans.size()-1;
        while(i < j)
        {
            if(ans[i] != ans[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool isPalindrome(int x) {
        string ans = to_string(x);
        return isPalindrome(ans);
    }
};