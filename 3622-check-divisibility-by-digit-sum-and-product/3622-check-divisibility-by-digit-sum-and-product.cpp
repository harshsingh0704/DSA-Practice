class Solution {
public:
    bool checkDivisibility(int n) {
        int sum =0;
        int pro=1;
        int original=n;
        while (n>0){
        int digit =n%10;
        sum =digit+sum;
        pro=digit*pro;
        n = n / 10;
        }
        if(original%(sum+pro)==0){
            return true ;
        }
        else return false ;
    }
};