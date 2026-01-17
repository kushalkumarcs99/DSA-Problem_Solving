class Solution {
public:
    bool canPermutePalindrome(string s) {
        int n = s.size();
        unordered_map<char, int> hash;

        for(auto & ele : s)
        {
            hash[ele]++;
        }

        int oddCount = 0;
        for(auto it : hash)
        {
            if(it.second%2!=0)
            {
                oddCount++;
            }
        }
        
        return oddCount > 1 ? false : true;
    }
};