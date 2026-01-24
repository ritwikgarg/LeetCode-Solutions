class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        generateSubsets(ans, nums, curr, 0);
        return ans;
    }

    void generateSubsets(vector<vector<int>>& ans, vector<int>& nums, vector<int>& curr, int currIndex) {
        if (currIndex == nums.size()) {
            ans.push_back(curr);
            return;
        }
        // Include currIndex
        curr.push_back(nums[currIndex]);
        generateSubsets(ans, nums, curr, currIndex+1);
        curr.pop_back();

        // Exclude currIndex
        generateSubsets(ans, nums, curr, currIndex+1);
    }
};