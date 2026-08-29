class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int>ans ;
        ans .push_back(0);
        int res =0;
        int n=gain.size();
        for( int i =0; i< n ; i++){
            int x =ans[i]+gain[i];
        ans.push_back(x);
        res =max(res,(ans[i+1]));
        }
        return res ;
    }
};