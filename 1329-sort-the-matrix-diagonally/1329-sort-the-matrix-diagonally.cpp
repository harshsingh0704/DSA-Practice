
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        // Start diagonals from every column in first row
        for (int col = 0; col < n; col++) {

            vector<int> temp;

            int i = 0, j = col;

            // Extract diagonal
            while (i < m && j < n) {
                temp.push_back(mat[i][j]);
                i++;
                j++;
            }

            // Sort diagonal
            sort(temp.begin(), temp.end());

            // Put elements back
            i = 0, j = col;
            int k = 0;

            while (i < m && j < n) {
                mat[i][j] = temp[k];
                k++;
                i++;
                j++;
            }
        }

        // Start diagonals from first column (excluding row 0)
        for (int row = 1; row < m; row++) {

            vector<int> temp;

            int i = row, j = 0;

            // Extract diagonal
            while (i < m && j < n) {
                temp.push_back(mat[i][j]);
                i++;
                j++;
            }

            // Sort diagonal
            sort(temp.begin(), temp.end());

            // Put elements back
            i = row, j = 0;
            int k = 0;

            while (i < m && j < n) {
                mat[i][j] = temp[k];
                k++;
                i++;
                j++;
            }
        }

        return mat;
    }
};
