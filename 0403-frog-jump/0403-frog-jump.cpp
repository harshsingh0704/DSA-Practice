class Solution {
public:
   
    bool solve(vector<int>& stones, int idx, int k,
           vector<vector<int>>& dp) {

    if(idx == stones.size()-1)
        return true;

    if(dp[idx][k] != -1)
        return dp[idx][k];

    for(int j = k-1; j <= k+1; j++) {
        if(j <= 0) continue;

        int nextPos = stones[idx] + j;

        for(int i = idx+1; i < stones.size(); i++) {
            if(stones[i] == nextPos) {
                if(solve(stones, i, j, dp))
                    return dp[idx][k] = true;
            }
        }
    }

    return dp[idx][k] = false;
}
    bool canCross(vector<int>& stones) {
        int n =stones.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve (stones, 0 ,0, dp);
    }
};