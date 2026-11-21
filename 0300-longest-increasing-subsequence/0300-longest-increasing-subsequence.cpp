class Solution {
public: 
int solve( int idx,int j ,vector<int>&nums,vector<vector<int>>&dp){
    if(idx==nums.size()) return 0;

    if(dp[idx][j+1]!=-1) return dp[idx][j+1];
    int notpick=solve(idx+1,j,nums,dp);
    int pick=0;
    if(j==-1||nums[idx]>nums[j]){
        pick=1+solve(idx+1,idx,nums,dp);
    }
    return dp[idx][j+1]=max(pick,notpick);
}
    int lengthOfLIS(vector<int>& nums) {
        int n =nums.size();
        vector<vector<int>>dp(n, vector<int>(n+1,-1));
        return solve(0,-1,nums,dp);
    }
};