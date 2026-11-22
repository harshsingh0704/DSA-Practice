
class Solution {
public:
    int count = 0;

    void solve(int index, int n, vector<int>& vis) {

        if (index > n) {
            count++;
            return;
        }

        for (int i = 1; i <= n; i++) {

            if (!vis[i] &&
                (i % index == 0 || index % i == 0)) {

                vis[i] = 1;

                solve(index + 1, n, vis);

                vis[i] = 0;
            }
        }
    }

    int countArrangement(int n) {

        vector<int> vis(n + 1, 0);

        count = 0;

        solve(1, n, vis);

        return count;
    }
};
