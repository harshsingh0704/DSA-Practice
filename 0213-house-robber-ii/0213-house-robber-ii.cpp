class Solution {
public:
   long long int robhelp(vector<int>& nums,int start, int end) {
        int prev =0;
        int prev2=0; 
        int cur=0;
        for (int i =start; i<= end ; i++){
            int take =nums[i];
                take+=prev2;
            
           int nontake=prev;
              cur =max(take , nontake);
              prev2=prev;
              prev =cur ;
        
        }
      
        return prev ;
    }
      int rob(vector<int>&nums){
        int n = nums.size();
         if (n == 1)
            return nums[0];
        int ans1=robhelp(nums,0,n-2);
        int ans2 =robhelp(nums,1,n-1);
        return max(ans1,ans2);
    }
};