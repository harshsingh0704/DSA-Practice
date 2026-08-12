class Solution {
public:

    bool containsDuplicate(vector<int>& nums) {

        // Hash map to store frequency of elements
        unordered_map<int, int> hash;

        // Traverse array
        for(int i = 0; i < nums.size(); i++) {

            // If element already exists in hash map
            if(hash[nums[i]] > 0) {
                return true;
            }

            // Store/increase frequency
            hash[nums[i]]++;
        }

        // No duplicates found
        return false;
    }
};