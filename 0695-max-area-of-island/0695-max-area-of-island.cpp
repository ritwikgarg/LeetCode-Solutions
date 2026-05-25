class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n,0));

        int maxArea = 0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (!visited[i][j] && grid[i][j]==1) {
                    int area = dfs(m, n, grid, i, j, visited);
                    maxArea = max(area, maxArea);
                }
            }
        }

        return maxArea;
    }

    int dfs(int m, int n, vector<vector<int>>& grid, int row, int col, vector<vector<int>>& visited) {
        if (grid[row][col] == 0) return 0;

        visited[row][col] = 1;
        int area = 1;
        
        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, -1, 0, 1};
        
        for (int i=0; i<4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow>=0 && nrow<m && ncol>=0 && ncol<n && !visited[nrow][ncol] && grid[nrow][ncol]==1){
                area += dfs(m, n, grid, nrow, ncol, visited);
            }
        }

        return area;
    }
};