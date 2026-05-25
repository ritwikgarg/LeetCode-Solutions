class Solution {
public:
    int climbStairs(int n) {
        // Using memoization -> top-down recursion + caching
        // So we want to start from dfs(n) and go down to base case
        vector<int> dp(n+1, -1);
        return dfs(n, dp);
    }

    int dfs(int n, vector<int>& dp) {
        if (n == 0 || n == 1) return 1;

        if (dp[n] != -1) return dp[n];

        dp[n] = dfs(n-1, dp) + dfs(n-2, dp);

        return dp[n];
    }
};