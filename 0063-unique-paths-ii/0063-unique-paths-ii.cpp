class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // Using memoization
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if (obstacleGrid[0][0] == 1) return 0;
        if (obstacleGrid[m-1][n-1] == 1) return 0;

        return findPaths(m, n, obstacleGrid);
    }

    int findPaths(int rows, int cols, vector<vector<int>>& obstacleGrid) {

        vector<vector<int>> dp(rows, vector<int>(cols, -1));
        dp[0][0] = 1;

        for (int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                if (i==0 && j==0) continue;

                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }

                int prevRow = 0;
                int prevCol = 0;
                if (i-1 >=0) prevRow = dp[i-1][j];
                if (j-1 >=0) prevCol = dp[i][j-1];

                dp[i][j] = prevRow + prevCol;
            }
        }

        return dp[rows-1][cols-1];
    }
};