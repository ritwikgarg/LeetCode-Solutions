class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int totSum = 0;
        for (int i=0; i<n; i++) totSum += nums[i];

        if (totSum % 2 != 0) return false;
        int target = totSum/2;

        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

        for (int i=0; i<n; i++) {
            dp[i][0] = true; // by not picking the element at index i we can always find target = 0

            if (nums[i] <= target) dp[i][nums[i]] = true; // by picking the element at index i we can always find target = nums[i]
        }

        for (int i=1; i<n; i++) {
            for (int sum=1; sum<=target; sum++) {
                bool dontTakeAtI = dp[i-1][sum];
                bool takeAtI = false;
                if (sum - nums[i] >= 0)  takeAtI = dp[i-1][sum - nums[i]];

                dp[i][sum] = takeAtI | dontTakeAtI;
            }
        }

        return dp[n-1][target];
    }
};