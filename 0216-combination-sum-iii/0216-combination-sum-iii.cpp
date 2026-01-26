class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> curr;
        vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        findCombinations(ans, k, n, nums, curr, 0, 0);
        return ans;
    }

    void findCombinations(vector<vector<int>>& ans, int k, int n, vector<int>& nums, vector<int>& curr, int currIndex, int currSum) {
        if (curr.size() == k || currIndex == nums.size()) {
            if (curr.size() == k && currSum == n) {
                ans.push_back(curr);
            }
            return;
        }

        curr.push_back(nums[currIndex]);
        findCombinations(ans, k, n, nums, curr, currIndex+1, currSum+nums[currIndex]);
        curr.pop_back();

        findCombinations(ans, k, n, nums, curr, currIndex+1, currSum);
    }
};