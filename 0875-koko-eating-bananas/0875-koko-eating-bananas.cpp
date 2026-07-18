class Solution {
public: 
       int fmax(vector<int>& piles){
        int n =piles.size();
        int maxi =INT_MIN;
        for(int i =0; i<n; i++){
           maxi =max(maxi ,piles[i]);
        }
        return maxi ;
       }
        long long calculateTotalHours(vector<int>& piles, int speed) {
        long long  totalH = 0;
        for (int bananas : piles) {
            totalH += ((long long)bananas + speed - 1) / speed;
        }
        return totalH;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int left=1;
        int right=fmax(piles);
        int ans =right;
        while(left<=right){
            int mid = left + (right - left) / 2;
            long long  totalH=calculateTotalHours(piles,mid);
            if(totalH<=h){
                ans =mid ;
                right=mid -1;

            }
            else {
                left=mid+1;
            }
        }
        return ans;
    }
};