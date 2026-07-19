class Solution {
public:
 int fmax(vector<int>& bloomDay){
    int maxi =INT_MIN;
    int n = bloomDay.size();
    for (int i =0 ; i< n; i++){
      maxi = max (maxi , bloomDay[i]);

    }
    return  maxi;
 }
 int fmin(vector<int>& bloomDay){
    int mini =INT_MAX;
    int n = bloomDay.size();
    for ( int i =0 ; i < n ; i++){
        mini = min (mini , bloomDay[i]);

    }
    return mini ; 
 }
 bool solve(vector<int>& bloomDay,int day, int m, int k){
    int cnt =0 ; int nd=0;
     int n = bloomDay.size();
    for(int i =0; i<n; i++){
        if(bloomDay[i]<=day){
            cnt ++;

        }
        else {
            nd+=cnt/k;
            cnt =0;

        }
        
    }
    nd+=cnt/k;
    if(nd>=m){

    return true;
    }
    else {
        return false ;
    }
}
    long long minDays(vector<int>& bloomDay, int m, int k) {
        int  low =fmin(bloomDay);
        int  high =fmax(bloomDay);
        int  n =bloomDay.size();
       
        if ((long long)m * k > n) return -1;//integer overflow fix 
        int ans =0;
        while(low<=high){
            int mid =(low+high)/2;
            if(solve(bloomDay,mid, m , k)==true){
                ans = mid;
                high=mid-1;
            }
            else {
                low = mid +1;
            }
        }
        return ans ;
    }
};