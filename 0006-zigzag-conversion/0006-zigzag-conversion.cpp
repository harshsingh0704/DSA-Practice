class Solution {
public:
    string convert(string s, int numRows) {
        int n =s.size();
        string ans;
        if(numRows==1) return s;
        int charsection=2*(numRows-1);
        for(int i =0 ; i < numRows;i++){
            int index =i;
            while(index<n){
                ans+=s[index];
                if(i!=0&&i!=numRows-1){
                    int charinbetween =charsection-2*(i);
                    int secondindex=index +charinbetween;
                    if(secondindex<n){
                        ans +=s[secondindex];
                    }
                }
                index+=charsection;
            }
        }
        return ans ;
    }
};