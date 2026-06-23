class Solution {
public:
    int atMost(vector<int>& nums, int k) {
       int left=0;
       int sum =0;
       int cnt =0; 
       int oddcount=0;
       for(int i =0; i<nums.size();i++){
          if(nums[i]%2==1){
            oddcount++;
          }
          while(oddcount>k){
            if(nums[left]%2==1){
            oddcount--; 
          }
             left++;
       } 
       cnt +=(i-left+1);
       }
       return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {

        return atMost(nums, k) - atMost(nums, k - 1);
    }
};