class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for (int i=0; i<n; i++) {
            while ((nums[i] > 0 && nums[i] <= n) && (nums[i] - 1 != i)) {
                int index = nums[i] - 1;
                swap(nums[i], nums[index]);
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1)
                return i + 1;
        }

        return n+1;
    }
};