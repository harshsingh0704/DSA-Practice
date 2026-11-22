
class Solution {
public:
    vector<string> ans;

    void solve(string &s, int index, int dots, string temp) {

        if (dots == 4 && index == s.size()) {
            temp.pop_back();
            ans.push_back(temp);
            return;
        }

        if (dots >= 4 || index >= s.size()) {
            return;
        }

        for (int len = 1; len <= 3 && index + len <= s.size(); len++) {

            string part = s.substr(index, len);

            // Leading zero check
            if (part.size() > 1 && part[0] == '0') {
                break;
            }

            int num = stoi(part);

            if (num > 255) {
                break;
            }

            solve(s, index + len, dots + 1, temp + part + ".");
        }
    }

    vector<string> restoreIpAddresses(string s) {

        ans.clear();

        if (s.size() < 4 || s.size() > 12) {
            return ans;
        }

        solve(s, 0, 0, "");

        return ans;
    }
};
