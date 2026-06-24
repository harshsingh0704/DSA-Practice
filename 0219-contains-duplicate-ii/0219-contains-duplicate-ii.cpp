class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        // Stores: number -> last index where it appeared
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {

            // Check if current number has been seen before
            if (mp.find(nums[i]) != mp.end()) {

                // Distance between current index and previous index
                if (i - mp[nums[i]] <= k) {
                    return true;
                }
            }

            // Update the latest index of the current number
            mp[nums[i]] = i;
        }

        // No valid duplicate found
        return false;
    }
};