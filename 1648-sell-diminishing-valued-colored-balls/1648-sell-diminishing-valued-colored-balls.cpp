class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        sort(inventory.begin(), inventory.end(), greater<int>());
        int n = inventory.size();
        
        int low = 0;
        int high = inventory[0];

        // Idea: BS on answers
        // Search for a threshold 'k' such that total number of balls with values that can be sold above k is >= orders
        // Sum the max values until this point
        // Now decrease k to make sure we don't return an inflated maxValue
        int k = 0;
        while (low <= high) {
            int mid = low + (high-low)/2;
            if (isPossible(inventory, orders, mid)) {
                low = mid+1;
            } else {
                k = mid;
                high = mid-1;
            }
        }

        // k represent the ball value in our original array upto which we need to satisfy orders while maximizing value
        // We now have to calculate the sum of all the balls upto k
        int numBallsSold = 0;
        long long maxValue = 0;
        int mod = 1e9+7;
        for (int i=0; i<n; i++) {
            if (inventory[i] > k) {
                long long count = inventory[i] - k;
                maxValue = ((maxValue + (1LL *(inventory[i] + k+1) * count)/2) % mod ) % mod; // Sn - Sk = (n+k) * count  
                numBallsSold += count;
            } 
        }
        if (numBallsSold < orders) {
            int ballsRequired = orders - numBallsSold;
            maxValue = (maxValue + ballsRequired * 1LL * k) % mod;
        }

        return maxValue;
    }

    bool isPossible(vector<int>& inventory, int orders, int k) {
        long long ballsThatCanBeSold = 0;
        for (int i = 0; i < inventory.size(); i++) {
            if (inventory[i] > k) {
                ballsThatCanBeSold += inventory[i] - k;   
                if (ballsThatCanBeSold >= orders) {
                    return true;
                }
            }
        }

        return false;
    }
};