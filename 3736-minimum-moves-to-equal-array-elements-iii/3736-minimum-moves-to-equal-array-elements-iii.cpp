class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = 0;
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            maxi = max(maxi, nums[i]);
            sum += nums[i];
        }

        return maxi * nums.size() - sum;
    }
};