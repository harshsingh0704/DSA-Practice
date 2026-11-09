class Solution {
public:
    int smallestEvenMultiple(int n) {
        int x=0;
        if(n==1) return 2;
        for( int i =1; i < n ; i++){
          int m=n*i;
            if(m%2==0&&m%n==0){
                x=m;
                break;
            }
        }
        return x ;
    }
};