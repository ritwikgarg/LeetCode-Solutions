class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        findPermutations(ans, nums, 0);
        return ans;
    }

    void findPermutations(vector<vector<int>>& ans, vector<int>& nums, int currIndex) {
        if (currIndex == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for (int i=currIndex; i<nums.size(); i++) {
            swap(nums[currIndex], nums[i]);
            findPermutations(ans, nums, currIndex+1);
            swap(nums[i], nums[currIndex]);
        }
        
    }
};