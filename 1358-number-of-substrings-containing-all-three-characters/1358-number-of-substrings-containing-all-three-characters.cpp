class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int left =0;
        int ans=0;
        unordered_map<char, int>mp;
        for(int i =0; i<n ; i++){
            mp[s[i]]++;
           while(mp.size()==3){
            ans+=n-i;
            mp[s[left]]--;
            if(mp[s[left]]==0){
                mp.erase(s[left]);
            }
            left++;
           }
        }
        return ans;
    }
};