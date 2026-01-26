class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        generateSubsetsWithoutDuplicates(ans, nums, curr, 0);
        return ans;
    }

    void generateSubsetsWithoutDuplicates(vector<vector<int>>& ans, vector<int>& nums, vector<int> curr, int currIndex) {
        if (currIndex == nums.size()) {
            ans.push_back(curr);
            return;
        }

        // Pick current element;
        curr.push_back(nums[currIndex]);
        generateSubsetsWithoutDuplicates(ans, nums, curr, currIndex+1);
        curr.pop_back();

        // If we are not picking current element, then we also don't want to pick any duplicate of the current element
        int currNum = nums[currIndex];
        int i = currIndex+1;
        while (i < nums.size() && nums[i] == currNum) {
            i++;
        }
        generateSubsetsWithoutDuplicates(ans, nums, curr, i);
    }

};