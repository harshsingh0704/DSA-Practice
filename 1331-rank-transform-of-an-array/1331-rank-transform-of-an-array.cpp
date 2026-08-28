class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
       vector<int>ans;
     int n =arr.size();
       map<int,int>mp;
       for( int i =0; i<n ; i++){
         mp[arr[i]]++;
       }
       int rank =1;
       for(auto &p:mp){
        p.second=rank;
        rank++;
       }
       for( int i =0 ; i< n ; i++){
        arr[i]=mp[arr[i]];
       }
       return arr;
    }
};