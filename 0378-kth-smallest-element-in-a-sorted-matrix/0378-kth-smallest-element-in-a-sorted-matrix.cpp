class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n =matrix.size();
        int m =matrix[0].size();
        vector<int>final;
        for( int  i =0 ;i < n ; i++ ){
            for( int j=0;j<m; j++){
               final.push_back(matrix[i][j]);
            }
        }
        sort(final.begin(),final.end());
        return final[k-1];
          
  }
};