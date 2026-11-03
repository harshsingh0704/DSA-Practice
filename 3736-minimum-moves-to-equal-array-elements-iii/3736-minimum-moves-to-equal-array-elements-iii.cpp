class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n =nums.size();
        int moves=0;
        int maxi=0;
   for( int  j =0 ; j <n ; j++){
    maxi =max(maxi,nums[j]);
   }
        for (int i =0  ; i < n ; i ++){
        moves+=maxi-nums[i];
        }
        return moves;
    }
};