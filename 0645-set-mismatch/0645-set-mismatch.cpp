class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<int>ans;
        int n =nums.size();
        int tot=n*(n+1)/2;
        int mis =0;
        int sum =0;
        for( int i =0 ; i< n ; i++){
            mp[nums[i]]++;
            sum=nums[i]+sum;
            
            if(mp[nums[i]]>1){
                ans.push_back(nums[i]);
            }
        }
        mis =tot-sum+ans[0];
        ans.push_back(mis);
        return ans ;
        

    }
};