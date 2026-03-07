class Solution {
public:
    string trimTrailingVowels(string s) {
        unordered_set<char> vowels = {'a','e','i','o','u'};
        
        int i = s.size() - 1;

        while(i >= 0 && vowels.count(s[i])) {
            i--;
        }

        return s.substr(0, i + 1);
    }
};