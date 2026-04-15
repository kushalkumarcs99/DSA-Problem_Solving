class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> result(n, 0);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--) {
            int count = 0;

            // Remove all shorter people
            while(!st.empty() && st.top() < heights[i]) {
                st.pop();
                count++;
            }

            // If someone taller exists, they are visible
            if(!st.empty()) {
                count++;
            }

            result[i] = count;

            st.push(heights[i]);
        }

        return result;
    }
};