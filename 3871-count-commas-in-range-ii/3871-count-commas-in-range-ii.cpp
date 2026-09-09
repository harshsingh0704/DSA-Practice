class Solution {
public:
    long long countCommas(long long n) {
        long long cnt = 0;
        
        if (n >= 1000)
            cnt += n - 999;  // 1 comma
        
        if (n >= 1000000)
            cnt += n - 999999;  // 2nd comma
        
        if (n >= 1000000000)
            cnt += n - 999999999;  // 3rd comma
        
        if (n >= 1000000000000LL)
            cnt += n - 999999999999LL;  // 4th comma
        
        if (n >= 1000000000000000LL)
            cnt += n - 999999999999999LL;  // 5th comma
        
        return cnt;
    }
};