
class Solution {
public:
    int solve(vector<vector<int>>& matrix, int i, int j,
              vector<vector<int>>& dp,
              vector<vector<bool>>& visited) {

        int m = matrix[0].size();

        if(j < 0 || j >= m)
            return 1000000000;

        if(i == 0)
            return matrix[0][j];

        if(visited[i][j])
            return dp[i][j];

        int s = matrix[i][j] +
                solve(matrix, i-1, j, dp, visited);

        int ld = matrix[i][j] +
                 solve(matrix, i-1, j-1, dp, visited);

        int rd = matrix[i][j] +
                 solve(matrix, i-1, j+1, dp, visited);

        visited[i][j] = true;

        return dp[i][j] = min(s, min(ld, rd));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        int ans = INT_MAX;

        for(int j = 0; j < m; j++) {
            ans = min(ans, solve(matrix, n-1, j, dp, visited));
        }

        return ans;
    }
};
