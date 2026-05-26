class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // Using memoization
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if (obstacleGrid[0][0] == 1) return 0;
        if (obstacleGrid[m-1][n-1] == 1) return 0;

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return findPaths(m-1, n-1, m-1, n-1, obstacleGrid, dp);
    }

    int findPaths(int row, int col, int m, int n, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp) {
        if (row ==0 && col == 0) return 1;

        if (row<0) return 0;
        if (col<0) return 0;

        if (obstacleGrid[row][col] == 1) return 0;

        if (dp[row][col] != -1) return dp[row][col];

        int prevRow = findPaths(row-1, col, m, n, obstacleGrid, dp);
        int prevCol = findPaths(row, col-1, m, n, obstacleGrid, dp);

        dp[row][col] = prevRow + prevCol;
        return dp[row][col];
    }
};