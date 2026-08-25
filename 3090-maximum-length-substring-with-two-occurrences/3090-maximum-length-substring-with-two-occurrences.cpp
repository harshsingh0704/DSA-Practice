class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int maxlen=0;
        int left =0;
        unordered_map<char,int>mp;
        for(int i =0 ; i< n ;i++){
            mp[s[i]]++;
            
            while(mp[s[i]]>2){
              mp[s[left]]--;
              left++;
            }
        
        maxlen=max(maxlen,i-left+1);
        }
        return maxlen;
    }
};