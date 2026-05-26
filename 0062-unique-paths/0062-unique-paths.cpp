class Solution {
public:
    int uniquePaths(int m, int n) {
        // Using memoization
        vector<vector<int>> dp(m, vector(n, 0));
        return pathCount(m-1, n-1, m-1, n-1, dp);
    }

    int pathCount(int row, int col, int m, int n, vector<vector<int>>& dp) {
        if (row==0 && col==0) return 1;

        if (row < 0) return 0;
        if (col < 0) return 0;

        if (dp[row][col] != 0) return dp[row][col];
        
        int downPath = 0;
        int rightPath = 0;

        rightPath = pathCount(row, col-1, m, n, dp);
        downPath = pathCount(row-1, col, m, n, dp);
        dp[row][col] = downPath + rightPath;
        return dp[row][col];
    }
};