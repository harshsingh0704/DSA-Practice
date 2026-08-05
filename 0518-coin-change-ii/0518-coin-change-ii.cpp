class Solution {
public:
  int f( vector<int>& coins,int ind , int target ,vector<vector<int>>&dp){
    if(ind==0){
        return(target%coins[0]==0);
    }
    if(dp[ind][target]!=-1) return dp[ind][target];
    int notpick=f(coins,ind-1,target,dp);
    int pick=0;
    if(coins[ind]<=target){
        pick=f(coins,ind,target-coins[ind],dp);
    }
    return dp[ind][target]=pick+notpick;
  }
    int change(int amount, vector<int>& coins) {

      int n =coins.size();
      vector<vector<int>>dp(n,vector<int>(amount+1,-1));
      return f(coins,n-1,amount,dp);

    }
};