class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();

        if(n != m) return false;

        unordered_map<char, int> hash;

        for(int i=0;i<n;i++)
        {
            hash[s[i]]++;
        }

        for(int i=0;i<m;i++)
        {
            if(hash.find(t[i]) == hash.end())
            {
                return false;
            }
            else{
                hash[t[i]]--;
            }
        }
        return true;
    }
};