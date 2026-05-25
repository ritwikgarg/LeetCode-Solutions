class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m,0));

        int count = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (!visited[i][j]  && grid[i][j] == '1') {
                    count++;
                    visited[i][j] = 1;
                    bfs(n, m, grid, i, j, visited);
                }
            }
        }

        return count;
    }

    void bfs(int n, int m, vector<vector<char>>& grid, int row, int col, vector<vector<int>>& visited) {
        
        queue<pair<int,int>> q; // stores row, col of node
        q.push({row, col});

        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            vector<int> drow = {-1, 0, 1, 0};
            vector<int> dcol = {0, -1, 0, 1};
            
            for (int i=0; i<4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if (nrow >=0 && nrow <n && ncol >=0 && ncol <m && !visited[nrow][ncol] && grid[nrow][ncol] == '1') {
                    visited[nrow][ncol] = 1;
                    bfs(n, m, grid, nrow, ncol, visited);
                }
            }
        }

    }
};