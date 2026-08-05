class Solution {
public:
 int f(vector<int>& nums,int ind, int target,vector<vector<int>>&dp){
    if(ind==0){
        if(target==0&&nums[0]==0) return 2;
        if(target==0||target==nums[0]) return 1;
        return 0;
    }
    if(dp[ind][target]!=-1) return dp[ind][target];
    int notpick=f(nums,ind-1,target,dp);
    int pick=0;
    if(nums[ind]<=target){
        pick=f(nums,ind-1,target-nums[ind],dp);
    }
    return pick+notpick;
 }
    int findTargetSumWays(vector<int>& nums, int target) {
       int totsum=accumulate(nums.begin(),nums.end(),0);
       if((totsum-target)<0 || (totsum-target)%2!=0) {
        return 0;
               }
               int subsetsum=(totsum-target)/2;
               vector<vector<int>>dp(nums.size(),vector<int>(subsetsum+1,-1));
               return f(nums,nums.size()-1,subsetsum,dp);
    }
};