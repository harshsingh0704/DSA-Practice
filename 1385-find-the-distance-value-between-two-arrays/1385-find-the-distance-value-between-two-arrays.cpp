class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int  n = arr1.size();
         int m = arr2.size();
         int cnt=0;
         for( int i =0 ; i < n ; i++){
            int j ;
            for( j =0; j < m ; j++){
                int x =arr1[i]-arr2[j];
                if(x<0){
                    x=x*-1;
                }
                if (x<=d){
                    break;
                }
               
                }
                 if(j==m){
                    cnt++;
            }
         }
         return cnt;
    }
};