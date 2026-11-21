
class Solution {
public:
    int solve(int i, int j, string &word1, string &word2,
              vector<vector<int>>& dp) {

        int n = word1.size();
        int m = word2.size();

        // Base cases
        if(i == n) return m - j;
        if(j == m) return n - i;

        // Memoization
        if(dp[i][j] != -1)
            return dp[i][j];

        // Characters match
        if(word1[i] == word2[j]) {
            return dp[i][j] =
                solve(i+1, j+1, word1, word2, dp);
        }

        // Characters don't match

        // INSERT
        int insertOp = 1 + solve(i, j+1, word1, word2, dp);

        // DELETE
        int deleteOp = 1 + solve(i+1, j, word1, word2, dp);

        // REPLACE
        int replaceOp = 1 + solve(i+1, j+1, word1, word2, dp);

        return dp[i][j] =
            min(insertOp, min(deleteOp, replaceOp));
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(0, 0, word1, word2, dp);
    }
};
