class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n =nums.size();
        sort(nums.begin(),nums.end());
        int sum=0;
        for(int  i =0 ; i <n ; i++){
            sum+=nums[i];
        
        }
        int median=0;
        if(n%2==0){
        median = (nums[n/2-1]+nums[n/2])/2;

        }
        else {
        

median = nums[n/2];
        }
        int moves=0;
        for( int j =0 ; j< n ; j++){
            if(nums[j]>median){

            
             moves +=nums[j]-median;
        }
        else {
            moves+=median-nums[j];
        }
        }
      return moves;
    }
};