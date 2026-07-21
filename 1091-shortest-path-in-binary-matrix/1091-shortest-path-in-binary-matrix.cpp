class Solution {
public:
    bool correct(vector<vector<int>>& grid, vector<vector<bool>>& vis, int row, int col){
        int rows = grid.size();
        int cols = grid[0].size();

        if(row<0 || col < 0 || row>=rows || col>= cols || grid[row][col] == 1 || vis[row][col]) return false;
        return true;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        if(grid[0][0] == 1) return -1;

        vector<vector<bool>> vis(rows, vector<bool>(cols, 0));
        vector<vector<int>> dist(rows, vector<int>(cols, -1));

        queue<pair<int,int>> q;
        q.push({0,0});
        vis[0][0] = true;
        dist[0][0] = 1;

        vector<pair<int,int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, -1}, {1, 1},{-1, 1}, {1, -1}};

        while(!q.empty()){
            auto [a, b] = q.front();
            q.pop();

            for(auto [i, j]: dirs){
                int dih = a+i;
                int nih = b+j;

                if(correct(grid, vis, dih, nih)){
                    vis[dih][nih] = true;
                    dist[dih][nih] = dist[a][b] + 1;
                    q.push({dih, nih});
                }
            }
        }

        return dist[rows-1][cols-1];


    }
};