class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1000000007;
        
        int n = s.size();

        // dp[i] = distinct subsequences of first i characters
        // including the empty subsequence
        vector<long long> dp(n + 1, 0);

        dp[0] = 1;  // empty subsequence

        // Last occurrence of each character
        vector<int> last(26, -1);

        for (int i = 1; i <= n; i++) {
            int c = s[i - 1] - 'a';

            // Add current character to every previous subsequence
            dp[i] = (2 * dp[i - 1]) % MOD;

            // Remove duplicates caused by previous occurrence
            if (last[c] != -1) {
                dp[i] = (dp[i] - dp[last[c] - 1] + MOD) % MOD;
            }

            last[c] = i;
        }

        // Remove empty subsequence
        return (dp[n] - 1 + MOD) % MOD;
    }
};