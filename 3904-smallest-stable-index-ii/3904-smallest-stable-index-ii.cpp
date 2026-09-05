
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n =nums.size();
        int maxi =INT_MIN;
    
        vector<int>suffix(n);
        suffix[n-1]=nums[n-1];
        for(int i =n-2;i>=0;i--){
            suffix[i]=min(nums[i],suffix[i+1]);
        }
        for(int i =0 ; i<n ; i++){
            maxi =max(maxi,nums[i]);
        
           int score=maxi-suffix[i];
          
            if(score<=k){
                return i;
            }
        }
        return -1;
    }
};