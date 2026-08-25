class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n =nums.size();
        for(int i =0 ; i< n ; i++){
            mp[nums[i]]++;

        }
        int m = k;
        int i =0;
        while(true){
        
            if(mp.find(m) == mp.end()){
                return m ;
            }
            m+=k;

        }
    }
};