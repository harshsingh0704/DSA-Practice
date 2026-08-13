class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Base case: only one pile
        for (int i = 0; i < n; i++) {
            dp[i][i] = piles[i];
        }

        // Build for increasing interval length
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                int j = i + len - 1;

                int takeLeft = piles[i] - dp[i + 1][j];
                int takeRight = piles[j] - dp[i][j - 1];

                dp[i][j] = max(takeLeft, takeRight);
            }
        }

        return dp[0][n - 1] > 0;
    }
};