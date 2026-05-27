class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();

        int totalSum = 0;
        for (int i=0; i<n; i++) totalSum += nums[i];

        int maxRes = 0;

        int f0 = 0;
        for (int i=0; i<n; i++) {
            f0 += nums[i] * i;
            maxRes = f0;
        }

        vector<int> dp(n, 0);
        dp[0] = f0;

        for (int i=1; i<n; i++) {
            dp[i] = dp[i-1] + totalSum - (n * nums[n-i]);
            maxRes = max(maxRes, dp[i]);
        }

        return maxRes;
    }
};