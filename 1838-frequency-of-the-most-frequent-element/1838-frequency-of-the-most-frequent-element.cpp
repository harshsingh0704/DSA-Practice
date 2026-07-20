class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
      int left =0; 
      long long sum =0;
      int ans =1;
      int n = nums.size();

      for(int right=0 ;right<n ; right++){
        sum+=nums[right];
        while((long long )nums[right] * (right - left + 1) - sum >k ){
            sum-=nums[left];
            left++;
        }
        ans =max(ans , right - left+1);
      }
      return ans ;
    }
};