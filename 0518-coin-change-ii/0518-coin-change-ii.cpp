class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        dp[0][0] = 1;
        return findCombinations(0, n, amount, coins, dp);
    }

    int findCombinations(int index, int n, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        if (amount == 0) {
            if (index < n) dp[index][amount] = 1;
            return 1;
        }

        if (index == coins.size() || amount < 0) {
            return 0;
        }

        if (dp[index][amount] != -1) return dp[index][amount];

        int take = findCombinations(index, n, amount - coins[index], coins, dp);
        int skip = findCombinations(index + 1, n, amount, coins, dp);

        dp[index][amount] = take + skip;
        return take + skip;
    }
};