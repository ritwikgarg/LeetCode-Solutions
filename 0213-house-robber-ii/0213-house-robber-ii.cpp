class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 0) return 0;
        if (n == 1) return nums[0];

        vector<int> temp1;
        vector<int> temp2;

        for (int i=0; i<n; i++) {
            if (i!=n-1) temp1.push_back(nums[i]);
            if (i!=0) temp2.push_back(nums[i]);
        }

        vector<int> dp1(n-1, INT_MIN);
        vector<int> dp2(n-1, INT_MIN);

        int skippingLastHouse = robHouse(n-2, temp1, dp1);
        int skippingFirstHouse = robHouse(n-2, temp2, dp2);

        return max(skippingFirstHouse, skippingLastHouse);
    }

    int robHouse(int i, vector<int>& nums, vector<int>& dp) {
        if (i==0) return nums[0];
        if (i==1) return max(nums[0], nums[1]);

        int prev2 = nums[0];
        int prev1 = max(nums[0], nums[1]);

        int n=nums.size();
        for (int i=2; i<n; i++) {
            int curr = max(prev1, nums[i] + prev2);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};