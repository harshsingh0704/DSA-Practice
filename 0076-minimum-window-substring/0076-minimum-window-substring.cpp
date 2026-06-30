class Solution {
public:
    string minWindow(string s, string t) {
        int n =s.size();
        int m=t.size();
        int minlen=INT_MAX;
        int sidx=-1;
        int l =0;
        int r =0;
        int cnt =0;
        unordered_map<char,int>mp;
        for(int i =0;i<m; i++){
        mp[t[i]]++;}

        while(r<n){
            if(mp[s[r]]>0) cnt++;
            mp[s[r]]--;
            while(cnt==m){
                if(r-l+1<minlen){
                    minlen=r-l+1;
                    sidx=l;
                    
                }
                 mp[s[l]]++;
                if(mp[s[l]]>0) cnt--;
                    l++;
            }
        r++;
        
        }  
        return minlen == INT_MAX
               ? ""
               : s.substr(sidx, minlen);
          }
};