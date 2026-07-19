class Solution {
public:
  int sumD(vector<int>& nums,int div ){
    int sum =0; int n =nums.size();
    for (int i =0; i< n ;i++){
        sum =sum+ceil((double(nums[i]))/(double)(div));

    }
    return sum;
  }
  int fmax(vector<int>& nums){
    int n= nums.size();
    int maxi = INT_MIN;
    for(int i =0 ; i<n ; i++){
        maxi = max (maxi, nums[i]);
    }
    return maxi ;
  }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n =nums.size();
        if(n >threshold) return -1 ; 
        int ans ;
          int low =1 ; int high = fmax(nums);
          while ( low <=high){
             int mid = low +(high -low )/2;
             if (sumD(nums , mid )<=threshold ){
                ans = mid ;
                high = mid -1;
             }
             else {
                low = mid +1;
             }
          }
          return ans ; 
    }
};