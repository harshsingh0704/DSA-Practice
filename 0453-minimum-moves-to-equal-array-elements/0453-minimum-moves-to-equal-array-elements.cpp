class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int cnt =0;
        sort(nums.begin(),nums.end());
        for( int i =1; i < n ; i++){
           
               cnt+=nums[i]-nums[0];
            
        }
      return cnt ;
    }
};