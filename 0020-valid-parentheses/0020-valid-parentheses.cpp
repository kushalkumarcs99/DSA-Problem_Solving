class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if (n == 1 || s[0] == ')' || s[0] == ']' || s[0] == '}')
            return false;
        stack<char> st;
        unordered_map<char, char> hash = {{')', '('}, {']', '['}, {'}', '{'}};

        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            } else {
                if (st.empty()) {
                    return false;
                }

                // Top doesn't match current closing bracket
                if (st.top() != hash[s[i]]) {
                    return false;
                }

                st.pop();
            }
        }
        return st.empty();
    }
};