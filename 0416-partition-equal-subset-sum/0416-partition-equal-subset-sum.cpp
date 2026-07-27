class Solution {
public:
    int f(int ind , int totsum,vector<int>&nums,vector<vector<int>>&dp){
        if(totsum==0) return true;
        if(ind==0) return (nums[0]==totsum);
        if(dp[ind][totsum]!=-1) return dp[ind][totsum];
        bool nontake=f(ind-1,totsum,nums,dp);
        bool take =false;
        if(nums[ind]<=totsum) take=f(ind-1,totsum-nums[ind],nums,dp);
        return dp[ind][totsum]=take||nontake;
    }
    bool canPartition(vector<int>& nums) {
        int n =nums.size();
        
        int sum=0;
        for(int i =0; i<n;i++){
            sum+=nums[i];
        }
        int totsum=0;
        if(sum%2==1){
            return false ;
        }
        else {

        
         totsum=sum/2;
        }
        vector<vector<int>>dp(n,vector<int>(totsum+1,-1));
        return f(n-1,totsum,nums,dp);
    }
};