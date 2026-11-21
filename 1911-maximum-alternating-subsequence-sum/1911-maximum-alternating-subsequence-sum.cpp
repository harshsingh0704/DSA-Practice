
class Solution {
public:
    long long solve(vector<int>& nums, int idx, int sign,
                    vector<vector<long long>>& dp) {

        if(idx == nums.size())
            return 0;

        if(dp[idx][sign] != -1)
            return dp[idx][sign];

        long long pick = 0;

        if(sign == 0) {
            pick = nums[idx] + solve(nums, idx+1, 1, dp);
        }
        else {
            pick = -nums[idx] + solve(nums, idx+1, 0, dp);
        }

        long long notpick = solve(nums, idx+1, sign, dp);

        return dp[idx][sign] = max(pick, notpick);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        vector<vector<long long>> dp(
            n, vector<long long>(2, -1)
        );

        return solve(nums, 0, 0, dp);
    }
};
