class Solution {
public:
    int rob(vector<int>& nums) {
        // Using memoization
        int n = nums.size();
        vector<int> dp(n, INT_MIN);
        return robHouse(n-1, nums, dp);
    }

    int robHouse(int n, vector<int>& nums, vector<int>& dp) {
        if (n == 0) return nums[0];
        if (n == 1) return max(nums[0], nums[1]);

        if (dp[n] != INT_MIN) return dp[n];

        int robCurrent = nums[n] + robHouse(n-2, nums, dp);
        int skipCurrent = robHouse(n-1, nums, dp);

        dp[n] = max(skipCurrent, robCurrent);
        return dp[n];
    }

};