
class Solution {
public:
    int m, n;

    bool dfs(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || j < 0 || i >= m || j >= n)
            return false;

        if (grid[i][j] == 1)
            return true;

        grid[i][j] = 1; // Mark visited

        bool up = dfs(i - 1, j, grid);
        bool down = dfs(i + 1, j, grid);
        bool left = dfs(i, j - 1, grid);
        bool right = dfs(i, j + 1, grid);

        return up && down && left && right;
    }

    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int cnt = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    if (dfs(i, j, grid)) {
                        cnt++;
                    }
                }
            }
        }

        return cnt;
    }
};
