class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if (n==0 || n==1) return 0;
        vector<int> dp(n+1, INT_MAX);

        return minCost(n, cost, dp);
    }

    int minCost(int n, vector<int>& cost, vector<int>& dp) {
        if (n==0 || n==1) return 0;

        if (dp[n] != INT_MAX) return dp[n];
        
        int oneStep = cost[n-1] + minCost(n-1, cost, dp);
        int twoStep = cost[n-2] + minCost(n-2, cost, dp);

        dp[n] = min(oneStep, twoStep);
        return dp[n];
    }
};