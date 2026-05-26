class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX); // dp[i] = min. no. of coins req to make amount i
        return findMinCoins(coins, amount, dp);
    }

private:
    int findMinCoins(vector<int>& coins, int amount, vector<int>& dp) {
        if (amount == 0) {
            return 0;
        }

        if (dp[amount] != INT_MAX) return dp[amount];

        int minCoins = INT_MAX;

        for (int coin : coins) {
            if (coin <= amount) {
                int remainingCoins = findMinCoins(coins, amount - coin, dp);

                if (remainingCoins != -1) {
                    minCoins = min(minCoins, 1 + remainingCoins);
                }
            }
        }

        if (minCoins == INT_MAX) {
            dp[amount] = -1;
            return -1;
        }

        dp[amount] = minCoins;
        return minCoins;
    }
};