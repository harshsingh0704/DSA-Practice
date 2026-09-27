class Solution {
public:
    string reverseParentheses(string s) {
        string st;

        for (char c : s) {
            if (c == ')') {
                string temp;

                while (st.back() != '(') {
                    temp += st.back();
                    st.pop_back();
                }

                st.pop_back(); // remove '('

                for (char x : temp) {
                    st.push_back(x);
                }
            }
            else {
                st.push_back(c);
            }
        }

        return st;
    }
};