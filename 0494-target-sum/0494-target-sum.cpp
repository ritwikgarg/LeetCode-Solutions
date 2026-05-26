class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        // Using memoization
        map<pair<int, int>, int> dp; // stores (index, val) , no. of ways
        return findWays(0, n, nums, 0, target, dp);
    }

    int findWays(int i, int n, vector<int>& nums, int currVal, int target, map<pair<int, int>, int>& dp) {
        
        if (i == n) {
            if (currVal == target) {
                dp[{i, currVal}] = 1;
                return 1;
            }
            dp[{i, currVal}] = 0;
            return 0;
        }

        if (dp.find({i, currVal}) != dp.end()) return dp[{i, currVal}];

        int positive = findWays(i+1, n, nums, currVal + nums[i], target, dp);
        int negative = findWays(i+1, n, nums, currVal - nums[i], target, dp);

        dp[{i, currVal}] = positive + negative;
        return positive + negative;
    }
};