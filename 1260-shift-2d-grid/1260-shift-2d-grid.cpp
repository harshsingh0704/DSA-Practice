class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m =grid.size();
        int n =grid[0].size();
        vector<vector<int>>ans(m,vector<int>(n));
         k = k % (m * n);
        for( int i = 0 ; i<grid.size();i++){
            for( int j =0; j<grid[0].size();j++){
               int oldidx=i*n+j;
                int newidx=(oldidx+k)%(n*m);
                int newrow=newidx/n;
                int newcol=newidx%n;
         ans[newrow][newcol]=grid[i][j];
            }
        }
        return ans;
    }
};