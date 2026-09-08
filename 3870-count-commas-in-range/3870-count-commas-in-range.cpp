class Solution {
public:
    long long countCommas(int n) {
        long long ans = 0;

        for (int i = 1000; i <= n; i++) {
            int x = i;

            while (x >= 1000) {
                ans++;
                x /= 1000;
            }
        }

        return ans;
    }
};