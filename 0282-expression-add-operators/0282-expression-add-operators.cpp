
class Solution {
public:
    void solve(string &num, int target, int pos,
               string path, long long val,
               long long prev, vector<string>& ans) {

        if (pos == num.size()) {
            if (val == target) {
                ans.push_back(path);
            }
            return;
        }

        for (int i = pos; i < num.size(); i++) {

            // Avoid leading zeros
            if (i > pos && num[pos] == '0')
                break;

            string cur = num.substr(pos, i - pos + 1);
            long long x = stoll(cur);

            // First number
            if (pos == 0) {
                solve(num, target, i + 1,
                      cur, x, x, ans);
            }
            else {
                // Addition
                solve(num, target, i + 1,
                      path + "+" + cur,
                      val + x, x, ans);

                // Subtraction
                solve(num, target, i + 1,
                      path + "-" + cur,
                      val - x, -x, ans);

                // Multiplication
                solve(num, target, i + 1,
                      path + "*" + cur,
                      val - prev + prev * x,
                      prev * x, ans);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;

        solve(num, target, 0, "", 0, 0, ans);

        return ans;
    }
};
