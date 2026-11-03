
class Solution {
public:
    void solve(int n, int open, int close,
               string s, vector<string>& ans) {

        // All brackets are used
        if (s.size() == 2 * n) {
            ans.push_back(s);
            return;
        }

        // Add opening bracket
        if (open < n) {
            solve(n, open + 1, close, s + "(", ans);
        }

        // Add closing bracket
        if (close < open) {
            solve(n, open, close + 1, s + ")", ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        solve(n, 0, 0, "", ans);

        return ans;
    }
};
