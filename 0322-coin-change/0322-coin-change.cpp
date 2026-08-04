class Solution {
public:
int f( int ind ,vector<int>& coins,int t,vector<vector<int>>&dp){
    if(ind==0){
        if(t%coins[0]==0) return t/coins[0];
        return 1e9;
    }
    if(dp[ind][t]!=-1) return dp[ind][t];
    int nontake=0+f(ind-1,coins,t,dp);
    int take=INT_MAX;
    if(coins[ind]<=t){
        take=1+f(ind ,coins,t-coins[ind],dp);
    }
    return dp[ind][t]=min(take,nontake);
}
    int coinChange(vector<int>& coins, int amount) {
        int n =coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans =f(n-1,coins,amount,dp);
        if(ans >=1e9){
            return -1;}
        else {
            return ans;
        }
    }
};