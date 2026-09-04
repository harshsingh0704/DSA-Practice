class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n =nums.size();
        int maxi =INT_MIN;
        int mini=INT_MAX;
        for(int i =0 ; i<n ; i++){
            maxi =max(maxi,nums[i]);
            for(int j =i ;j<n;j++){
                mini=min(mini,nums[j]);
            }
           int score=maxi-mini;
           mini=INT_MAX;
            if(score<=k){
                return i;
            }
        }
        return -1;
    }
};