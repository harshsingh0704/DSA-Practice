class Solution {
public:
    int solve(vector<int>& nums, int goal) {
         if(goal < 0) return 0;

        int n = nums.size();
        int left =0;
        int cnt=0;
        int sum =0;
        for(int i =0; i<n;i++){
            sum+=nums[i];
           
                while(sum>goal){ 
                sum =sum-nums[left];
                left++;
            }
        
         cnt += (i - left + 1);
        
        }
        return cnt;
    }
     int numSubarraysWithSum(vector<int>& nums, int goal) {

        return solve(nums, goal) -
               solve(nums, goal - 1);
     }
};