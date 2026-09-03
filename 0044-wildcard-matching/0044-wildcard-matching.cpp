class Solution {
public:
    bool solve(string &s, string &p, int i, int j,
               vector<vector<int>> &dp) {

        // Both are completely matched
        if (i < 0 && j < 0)
            return true;

        // String finished:
        // remaining pattern must contain only '*'
        if (i < 0) {
            for (int k = 0; k <= j; k++) {
                if (p[k] != '*')
                    return false;
            }
            return true;
        }

        // Pattern finished but string remains
        if (j < 0)
            return false;

        if (dp[i][j] != -1)
            return dp[i][j];

        // Character matches or '?'
        if (s[i] == p[j] || p[j] == '?') {
            return dp[i][j] =
                solve(s, p, i - 1, j - 1, dp);
        }

        // '*'
        if (p[j] == '*') {
            return dp[i][j] =
                solve(s, p, i - 1, j, dp) ||
                solve(s, p, i, j - 1, dp);
        }

        // Characters don't match
        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {

        int n = s.size();
        int m = p.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(s, p, n - 1, m - 1, dp);
    }
};