class Solution {
public:
 int f(string s1, string s2){
    int n =s1.size();
    int m =s2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    for(int i =0; i<=n;i++) dp[i][0]=0;
    for(int j =0;j<=m;j++) dp[0][j]=0;
    for(int ind1=1;ind1<=n;ind1++){
        for(int ind2=1;ind2<=m;ind2++){
            if(s1[ind1-1]==s2[ind2-1]){
                dp[ind1][ind2]=1+dp[ind1-1][ind2-1];
            }
            else{
                dp[ind1][ind2]=max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
            }
        }
    }
    return dp[n][m];
 }
    int longestPalindromeSubseq(string s) {
        string t =s;
        reverse(s.begin(),s.end());
        return f(s,t);

    }


    int minInsertions(string s) {
        return s.size()-longestPalindromeSubseq(s);
    }
};