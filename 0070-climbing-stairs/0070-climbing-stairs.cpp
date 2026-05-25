class Solution {
public:
    int climbStairs(int n) {
        // Using tabulation: bottom-up iteration
        // So we start at base case and then go to final ans
        vector<int> dp(n+1, -1);
        dp[0] = 1;
        dp[1] = 1;

        for (int i=0; i<n-1; i++) {
            dp[i+2] = dp[i] + dp[i+1];
        }

        return dp[n];
    }


};