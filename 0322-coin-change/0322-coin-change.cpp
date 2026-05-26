class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        return findMinCoins(coins, amount);
    }

private:
    int findMinCoins(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX); // dp[i] = min. no. of coins req to make amount i
        
        if (amount == 0) {
            return 0;
        }

        dp[0] = 0;
        for (int i=0; i<coins.size(); i++) {
            if (coins[i] <= amount) dp[coins[i]] = 1;
        }

        for (int i=1; i<=amount; i++) {
            int minCoins = INT_MAX;
            for (int j=0; j<coins.size(); j++) {
                int coin = coins[j];

                int coinsReq = INT_MAX;
                if (coin <= i) {
                    coinsReq = dp[i-coin];
                    minCoins = min(coinsReq, minCoins);
                }
            }
            if (minCoins != INT_MAX)  dp[i] = minCoins + 1;
        }

        if (dp[amount] == INT_MAX) return -1;
        return dp[amount];
    }
};