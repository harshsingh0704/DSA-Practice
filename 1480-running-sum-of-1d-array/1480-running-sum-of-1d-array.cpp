class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n =nums.size();
        int sum =0;
        vector<int>run;
        for( int i =0; i< n ;i++){
            sum+=nums[i];
            run.push_back(sum);
        }
        return run;
    }
};