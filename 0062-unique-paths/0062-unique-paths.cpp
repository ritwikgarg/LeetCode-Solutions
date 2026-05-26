class Solution {
public:
    int uniquePaths(int m, int n) {
        // Using tabulation
        return pathCount(m, n);
    }

    int pathCount(int m, int n) {
        vector<vector<int>> dp(m, vector(n, 0));

        dp[0][0] = 1;

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (i==0 && j==0) continue;
                
                int prevRow = 0;
                int prevCol = 0;

                if (i-1 >= 0) prevRow = dp[i-1][j];
                if (j-1 >= 0) prevCol = dp[i][j-1];

                dp[i][j] = prevRow + prevCol;
            }
        }
        
        return dp[m-1][n-1];
    }
};