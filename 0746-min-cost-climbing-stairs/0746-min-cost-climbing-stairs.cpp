class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if (n==0 || n==1) return 0;
        vector<int> dp(n+1, INT_MAX);
        int prev2 = 0;
        int prev1 = 0;

        for (int i=2; i<=n; i++) {
            int curr = min((prev1 + cost[i-1]), (prev2 + cost[i-2]));
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};