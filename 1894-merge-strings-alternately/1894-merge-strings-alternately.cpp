class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        int i = 0, j = 0;
        string result = "";
         while (i < n || j < m) {
            if (i < n) result += word1[i++];
            if (j < m) result += word2[j++];
        }
        return result;
    }
};