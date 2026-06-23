class Solution {
public:
    int characterReplacement(string s, int k) {
int n =s.size();
int left =0; 
int max_freq=0;
int maxlen=0;
unordered_map<char,int>mp;
for(int i =0; i<n; i++){
    mp[s[i]]++;
    max_freq=max(max_freq,mp[s[i]]);
while((i-left+1)-max_freq>k){
    mp[s[left]]--;
    left++;
}
maxlen =max(maxlen,i-left+1);
}
return maxlen;

    }
};