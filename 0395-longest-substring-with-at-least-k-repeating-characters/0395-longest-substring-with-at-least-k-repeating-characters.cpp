class Solution {
public:
    int longestSubstring(string s, int k) {
        int n =s.size();
        int ans =0;
        for( int target =1; target<=26 ; target++){
            unordered_map<char,int>mp;
            int unique=0;
            int atleastk=0;
            int left=0;
            for( int right =0; right<n ; right++){
            mp[s[right]]++;
            if(mp[s[right]]==1){
             unique++;}
             if(mp[s[right]]==k){
             atleastk++;}
             while(unique>target){
                mp[s[left]]--;
                if(mp[s[left]]==k-1){
                    atleastk--;
                }
                if(mp[s[left]]==0){
                    unique--;

                }
                
                    left++;
             }
             if(unique==target&&
                atleastk==unique){
                     ans = max(ans, right - left + 1);
                }

}
        }
        return ans ;
    }
};