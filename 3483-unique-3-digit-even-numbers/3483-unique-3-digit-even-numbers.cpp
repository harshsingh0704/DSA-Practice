class Solution {
public:
    set<int> ans;

    void solve(vector<int>& digits, vector<bool>& used,
               int index, int number) {

        // 3 digits selected
        if (index == 3) {
            ans.insert(number);
            return;
        }

        for (int i = 0; i < digits.size(); i++) {

            // This copy of the digit is already used
            if (used[i])
                continue;

            // First digit cannot be 0
            if (index == 0 && digits[i] == 0)
                continue;

            // Last digit must be even
            if (index == 2 && digits[i] % 2 != 0)
                continue;

            // Choose
            used[i] = true;

            solve(digits, used, index + 1,
                  number * 10 + digits[i]);

            // Backtrack
            used[i] = false;
        }
    }

    int totalNumbers(vector<int>& digits) {
        vector<bool> used(digits.size(), false);

        solve(digits, used, 0, 0);

        return ans.size();
    }
};