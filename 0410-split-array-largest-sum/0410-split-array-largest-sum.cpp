class Solution {
public:
bool solve (vector< int >&nums, int k , long long maxsum){
    int cnt =1; 
    long long sum =0; 
     int n=nums.size();
    for (int i =0; i< n ; i++){
    if(sum+nums[i]<=maxsum){
        sum+=nums[i];
    }
    else {
        cnt++;
        sum = nums[i];
        if(cnt>k){
            return false;
        }
    }
    }
    return true ; 
}
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
       long long low = *max_element(nums.begin(), nums.end());
        long long high = 0;
        for(int i =0; i< n ; i++) {
           high +=nums[i];
        }
      long long ans =0; 
      while(low<=high){

      
      long long  mid =low+(high - low )/2;
      if(solve(nums,k,mid)==true){
        ans = mid ; 
        high = mid -1;

      }
      else {
        low =mid +1;
      }
      }
      return (int)ans ;
    }
};