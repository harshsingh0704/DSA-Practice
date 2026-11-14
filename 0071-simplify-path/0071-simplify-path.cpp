
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string temp = "";

        for (int i = 0; i <= path.size(); i++) {
            if (i == path.size() || path[i] == '/') {

                if (temp == "..") {
                    if (!st.empty()) {
                        st.pop();
                    }
                }
                else if (temp != "" && temp != ".") {
                    st.push(temp);
                }

                temp = "";
            }
            else {
                temp += path[i];
            }
        }

        string ans = "";

        while (!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }

        return ans.empty() ? "/" : ans;
    }
};
