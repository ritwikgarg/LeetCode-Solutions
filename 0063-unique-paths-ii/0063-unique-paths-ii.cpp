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

        vector<int> dp(cols, 0);

        for (int i=0; i<rows; i++) {
            vector<int> temp(cols);
            for (int j=0; j<cols; j++) {
                if (i == 0 && j == 0) {
                    temp[j] = 1;
                    continue;
                }

                if (obstacleGrid[i][j] == 1) {
                    temp[j] = 0;
                    continue;
                }

                int prevRow = 0;
                int prevCol = 0;
                if (i-1 >=0) prevRow = dp[j];
                if (j-1 >=0) prevCol = temp[j-1];

                temp[j] = prevRow + prevCol;
            }
            dp = temp;
        }

        return dp[cols-1];
    }
};