class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        vector<char>ans;
        int n =word1.size();
        int m =word2.size();
        int i =0; 
        int j =0;
        while(i<n||j<m){
            if(i<n){
                ans.push_back(word1[i]);
                i++;
            }
            if(j<m){
                ans.push_back(word2[j]);
                j++;
            }
        }
       return string(ans.begin(), ans.end());
    }
};