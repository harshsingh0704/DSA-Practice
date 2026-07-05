class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int cnt=0;
      sort(intervals.begin(), intervals.end(),
     [](auto &a, auto &b){
         return a[1] < b[1];
     });
    
 int  prevEnd = intervals[0][1];

for(int i=1;i<n;i++){
    if(intervals[i][0] < prevEnd){
        cnt++;      // remove current interval
    }
    else{
        prevEnd = intervals[i][1];
    }
}
return cnt ;
    }
};