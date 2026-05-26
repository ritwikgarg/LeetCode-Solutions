class Solution {
public:
    int uniquePaths(int m, int n) {
        // Using tabulation
        return pathCount(m, n);
    }

    int pathCount(int m, int n) {
        vector<int> dp(n, 0);

        for (int i=0; i<m; i++) {
            vector<int> temp(n, 0);
            for (int j=0; j<n; j++) {
                if (i==0 && j==0) {
                    temp[0] = 1;
                    continue;
                } 

                int prevRow = 0;
                int prevCol = 0;

                if (i-1 >= 0) prevRow = dp[j];
                if (j-1 >= 0) prevCol = temp[j-1];

                temp[j] = prevRow + prevCol;
            }
            dp = temp;
        }
        
        return dp[n-1];
    }
};