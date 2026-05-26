class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return findWays(0, n, nums, 0, target);
    }

    int findWays(int i, int n, vector<int>& nums, int currVal, int target) {
        if (i == n) {
            if (currVal == target) return 1;
            return 0;
        }
        
        int number = nums[i];

        int positive = findWays(i+1, n, nums, currVal+number, target);
        int negative = findWays(i+1, n, nums, currVal-number, target);

        return positive+negative;
    }
};