class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;

        vector<int> left(nums.begin(), nums.begin() + n);
        vector<int> right(nums.begin() + n, nums.end());

        vector<vector<int>> leftSum(n + 1), rightSum(n + 1);

        // Left half
        for (int mask = 0; mask < (1 << n); mask++) {
            int bits = __builtin_popcount(mask);
            int sum = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i))
                    sum += left[i];
            }
            leftSum[bits].push_back(sum);
        }

        // Right half
        for (int mask = 0; mask < (1 << n); mask++) {
            int bits = __builtin_popcount(mask);
            int sum = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i))
                    sum += right[i];
            }
            rightSum[bits].push_back(sum);
        }

        for (int i = 0; i <= n; i++)
            sort(rightSum[i].begin(), rightSum[i].end());

        int total = accumulate(nums.begin(), nums.end(), 0);
        int ans = INT_MAX;

        for (int k = 0; k <= n; k++) {
            for (int s1 : leftSum[k]) {
                int target = total / 2 - s1;

                auto &v = rightSum[n - k];
                auto it = lower_bound(v.begin(), v.end(), target);

                if (it != v.end()) {
                    int chosen = s1 + *it;
                    ans = min(ans, abs(total - 2 * chosen));
                }

                if (it != v.begin()) {
                    --it;
                    int chosen = s1 + *it;
                    ans = min(ans, abs(total - 2 * chosen));
                }
            }
        }

        return ans;
    }
};