class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        int n = temperatures.size(); // Number of days

        vector<int> ans(n, 0); // Initially all answers are 0

        stack<int> st; // Stores indices of unresolved days

        // Traverse all temperatures
        for (int i = 0; i < n; i++) {

            // Current temperature is warmer than stack top
            while (!st.empty() &&
                   temperatures[i] > temperatures[st.top()]) {

                int idx = st.top(); // Previous colder day's index

                st.pop(); // Remove it from stack

                ans[idx] = i - idx; // Number of days waited
            }

            st.push(i); // Store current day's index
        }

        return ans;
    }
};