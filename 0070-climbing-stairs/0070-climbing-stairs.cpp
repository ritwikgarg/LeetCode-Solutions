class Solution {
public:
    int climbStairs(int n) {
        // Using memoization
        // dp[i] = number of ways to reach step 0 starting from step i
        vector<int> dp(n+1, -1);
        dp[0] = 1; // one way to be at 0: do nothing
        climb(n, dp);
        return dp[n];
    }

    void climb(int n, vector<int>& dp) {
        if (n == 0) {
            dp[n] = 0;
            return;
        }
        if (n == 1) {
            dp[n] = 1;
            return;
        }

        if (dp[n-1] == -1) climb(n-1, dp);
        if (dp[n-2] == -1) climb(n-2, dp);

        dp[n] = dp[n-1] + dp[n-2];
    }
};