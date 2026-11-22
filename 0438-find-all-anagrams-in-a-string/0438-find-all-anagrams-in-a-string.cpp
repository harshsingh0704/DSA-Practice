
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        int n = s.size();
        int m = p.size();

        unordered_map<char,int> mp;

        for(int i = 0; i < m; i++) {
            mp[p[i]]++;
        }

        vector<int> ans;
        int cnt = 0;
        int left = 0;

        for(int j = 0; j < n; j++) {

            if(mp[s[j]] > 0) {
                cnt++;
            }

            mp[s[j]]--;

            if(j - left + 1 > m) {

                if(mp[s[left]] >= 0) {
                    cnt--;
                }

                mp[s[left]]++;
                left++;
            }

            if(cnt == m) {
                ans.push_back(left);
            }
        }

        return ans;
    }
};
