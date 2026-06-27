class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int maxi =INT_MIN;
        int lsum=0;
        int rsum=0;

        for(int i =0 ; i<k; i++){
            lsum=lsum +cardPoints[i];

        }
        maxi = lsum;
        int ridx=n-1;
        for(int j =k-1;j>=0; j--){
            lsum=lsum-cardPoints[j];
            rsum= rsum+cardPoints[ridx];
            ridx=ridx-1;
            maxi = max(maxi,lsum+rsum);
        }
        return maxi;
    }
};