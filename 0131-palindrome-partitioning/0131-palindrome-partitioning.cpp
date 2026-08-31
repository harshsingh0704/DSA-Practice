class Solution {
public:
bool dpf(string s , int i , int j , vector<vector<int>>&dp){
    if(i>=j) return true ;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==s[j])
        return dp[i][j]=dpf(s,i+1,j-1,dp);
        
    
        return dp[i][j]=false ;
    
}
void solve(string s , int index , vector<string>&path,
           vector<vector<string>>&ans, vector<vector<int>>&dp){
            if(index ==s.size()){
                ans.push_back(path);
                return ;
            }
            for( int i = index ; i<s.size();i++){
                if(dpf(s,index,i,dp)){
                    path.push_back(s.substr(index,i-index+1));
                    solve(s,i+1,path, ans, dp);
                    path.pop_back();
                }
            }
           }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(n, -1));
        vector<vector<string>>ans;
        vector<string>path;
        solve(s, 0 , path, ans , dp);
        return ans;
    }
};