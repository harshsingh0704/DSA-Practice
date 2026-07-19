class Solution {
public:
int fmax(vector<int>& weights){
    int n= weights.size();
    int maxi = INT_MIN;
    for(int i =0 ; i<n ; i++){
        maxi = max (maxi, weights[i]);
    }
    return maxi ;
}
int solve (vector<int>& weights,int cap){
    int load =0; 
    int day =1;
    int n = weights.size();
    for ( int i =0; i<n ; i++){
        if (load+weights[i]>cap){
            day = day+1;
            load= weights[i];
        }
        else {
            load+=weights[i];
        }
     }
     return day;
}

    int shipWithinDays(vector<int>& weights, int days) {
        int low =fmax(weights);
        int high = accumulate(weights.begin(), weights.end(), 0);

        int ans =0; 
        while (low <= high ){
            int mid = low+(high - low )/2;
            int nd= solve (weights, mid ); 
            if(nd <= days ){
                ans = mid ;
                high = mid -1;
            }
            else {
                low =mid +1;
            }

    
        }
        return ans ;
    }
};