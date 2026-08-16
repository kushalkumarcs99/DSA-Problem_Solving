class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        vector<string> words;
        string word;
        while(ss >> word)
        {
            words.push_back(word+" ");
        }

        int left = 0, right = words.size()-1;
        while(left <= right)
        {
            string temp = words[left];
            words[left] = words[right];
            words[right] = temp;
            right--;
            left++;
        }

        string result = accumulate(words.begin(), words.end(), string(""));
        result.pop_back();
        return result;
    }
};