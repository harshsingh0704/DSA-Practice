class Solution {
public:
    int solve(int i, int j, int n,
              vector<vector<int>>& dp,
              vector<vector<bool>>& vis,
              vector<vector<int>>& triangle) {

        if (i == n - 1)
            return triangle[i][j];

        if (vis[i][j])
            return dp[i][j];

        int down = triangle[i][j] + solve(i + 1, j, n, dp, vis, triangle);
        int diag = triangle[i][j] + solve(i + 1, j + 1, n, dp, vis, triangle);

        vis[i][j] = true;
        return dp[i][j] = min(down, diag);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<vector<int>> dp(n, vector<int>(n));
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        return solve(0, 0, n, dp, vis, triangle);
    }
};