class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if (m == 1 && n == 1) return grid[0][0];

        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        dp[0][0] = grid[0][0];
        return minPathSum(m-1, n-1, grid, dp);
    }

    int minPathSum(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (row == 0 && col == 0) return grid[0][0];

        if (dp[row][col] != INT_MAX) return dp[row][col];

        int prevRow = INT_MAX;
        int prevCol = INT_MAX;
        
        if(row-1 >= 0) prevRow = grid[row][col] + minPathSum(row-1, col, grid, dp);
        if(col-1 >= 0) prevCol = grid[row][col] + minPathSum(row, col-1, grid, dp);

        dp[row][col] = min(prevRow, prevCol);
        return dp[row][col];
    }
};