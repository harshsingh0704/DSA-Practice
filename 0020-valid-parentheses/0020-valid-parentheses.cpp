class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (int i = 0; i < s.length(); i++) {

            // Push opening brackets
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            }
            else {

                // If stack is empty, invalid
                if (st.empty())
                    return false;

                char ch = st.top();
                st.pop();

                // Check matching brackets
                if ((s[i] == ')' && ch == '(') ||
                    (s[i] == ']' && ch == '[') ||
                    (s[i] == '}' && ch == '{')) {
                    continue;
                }
                else {
                    return false;
                }
            }
        }

        // Stack should be empty at end
        return st.empty();
    }
};