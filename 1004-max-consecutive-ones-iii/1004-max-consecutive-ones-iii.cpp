class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n =nums.size();
        int sum=0;
        int maxi =INT_MIN;
        int left=0;
        int countzeroes=0;
        for(int i =0; i<n;i++){
            if(nums[i]==0){
                countzeroes++;
            }
            while(countzeroes>k){
                if(nums[left]==0){
                    countzeroes--;
                
                }
                    left++;
               
            }
             maxi=max(maxi,i-left+1);
        }
        return maxi;
    }
};