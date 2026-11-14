class Solution {
public:
    int firstUniqChar(string s) {
        int  n =s.size();
        unordered_map<char,int>mp;

        for(int i =0;i<n;i++){
              mp[s[i]]++;

        }
        int low =0;
        while (low<n){
            if(mp[s[low]]<=1){
                return low;
            }
            low++;
        }
        
      return -1;
    }
};