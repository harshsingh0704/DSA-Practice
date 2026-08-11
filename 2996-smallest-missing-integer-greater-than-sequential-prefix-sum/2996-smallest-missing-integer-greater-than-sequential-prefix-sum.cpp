class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mp;

        // Store all numbers in the map
        for (int x : nums) {
            mp[x]++;
        }

        // Find sum of sequential prefix
        int sum = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            } else {
                break;
            }
        }

        // Find smallest number >= sum
        // that does not exist in nums
        int ans = sum;

        while (mp.count(ans)) {
            ans++;
        }

        return ans;
    }
};