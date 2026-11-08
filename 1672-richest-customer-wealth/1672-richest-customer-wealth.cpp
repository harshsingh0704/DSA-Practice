class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int sum =0;
        int n =accounts.size();
        int m =accounts[0].size();
        int maxi=INT_MIN;
        for( int i =0 ; i < n ; i++){
            for ( int j = 0 ; j< m; j ++){
                sum+=accounts[i][j];
                maxi=max(maxi,sum);
                
            }
            sum=0;
        }  
        return maxi;
    }
};