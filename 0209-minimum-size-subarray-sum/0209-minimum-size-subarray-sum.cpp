class Solution {
public:

    int minSubArrayLen(int target, vector<int>& nums) {

        int n = nums.size();

        int sum = 0;

        int cnt = 0;

        int minlen = INT_MAX;

        int left = 0;

        for(int i = 0; i < n; i++) {

            // Add current element
            sum += nums[i];

            // Increase current window size
            cnt++;

            // Window valid when sum >= target
            while(sum >= target) {

                // Update minimum length
                minlen = min(minlen, cnt);

                // Remove left element
                sum = sum - nums[left];

                // Move left pointer
                left++;

                // Reduce count
                cnt--;
            }
        }

        // No valid subarray found
        if(minlen == INT_MAX) {
            return 0;
        }

        return minlen;
    }
};