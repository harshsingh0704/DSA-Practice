class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int cnt =0;
         int mini =INT_MAX;
     for( int j =0 ; j < n ; j++){
      mini =min(mini , nums[j]);
     }
        for( int i =0; i < n ; i++){
           
               cnt+=nums[i]-mini;
            
        }
      return cnt ;
    }
};