class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int totalSum = 0;
        for (int i=0; i<n; i++) {
            totalSum += nums[i];
        }

        if (totalSum%2 != 0) return false;
        int target = totalSum/2;

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return partition(n-1, 0, nums, target, dp);
    }

    bool partition(int i, int currSum, vector<int>& nums, int target, vector<vector<int>>& dp) {
        if (currSum == target) return true;
        if (i < 0 || currSum > target) return false;

        if (dp[i][currSum] != -1) return dp[i][currSum];

        // Take i
        bool takeI = partition(i-1, currSum+nums[i], nums, target, dp);

        // Dont take i
        bool dontTakeI = partition(i-1, currSum, nums, target, dp);

        if (takeI || dontTakeI) {
            dp[i][currSum] = true;
            return dp[i][currSum];
        } 

        dp[i][currSum] = false;
        return dp[i][currSum];
    }
};