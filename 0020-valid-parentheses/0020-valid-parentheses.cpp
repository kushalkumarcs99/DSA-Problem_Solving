class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> mappings;

        mappings[')'] = '(';
        mappings[']'] = '[';
        mappings['}'] = '{';

        stack<char> st;

        for (char c : s) {
            if (mappings.find(c) == mappings.end()) {
                // Opening bracket
                st.push(c);
            } else {
                // Closing bracket
                if (st.empty())
                    return false;

                char topElement = st.top();
                st.pop();

                if (topElement != mappings[c])
                    return false;
            }
        }

        return st.empty();
    }
};