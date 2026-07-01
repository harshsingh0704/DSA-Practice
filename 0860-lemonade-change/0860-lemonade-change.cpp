class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
       int n =bills.size();
      int cnt1 =0;
      int cnt2=0;
      for(int i =0; i<n ; i++)
      {
        if(bills[i]==5){
            cnt1++;
        }
        else if (bills[i]==10){
            cnt2++;
        if(cnt1>0){
            cnt1--;
        }
        else {
            return false ;
        }
        }
        else {
            if(cnt2>0&&cnt1>0){
                cnt1--;
                cnt2--;
            
            }
            else if (cnt1>=3){
                cnt1 = cnt1-3;
            }
            else {
                return false ;
            }
        }
      }
      return true ;
    }
};