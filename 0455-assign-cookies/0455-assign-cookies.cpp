class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int l =0;
        int r =0;
        int cnt=0;
        int m =g.size();
        int n =s.size();
        while(l<m&&r<n){
       if(g[l]<=s[r]){
        cnt++;
        r++;
        l++;
        }
        else{
            r++;
        }
        
    }
    
       return cnt;
    }
};