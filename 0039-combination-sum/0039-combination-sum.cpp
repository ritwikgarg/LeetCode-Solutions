class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        calcCombinations(ans, candidates, target, curr, 0, 0);
        return ans;
    }

    void calcCombinations(vector<vector<int>>& ans, vector<int>& candidates, int target, vector<int>& curr,  int currIndex, int currSum) {

        if (currIndex == candidates.size() || currSum >= target) {
            if (currSum == target) {
                ans.push_back(curr);
            }
            return;
        }

        // At each index, we will choose whether to pick the same index again of move ahead

        // pick the same index again
        curr.push_back(candidates[currIndex]);
        if (currSum + candidates[currIndex] <= target) {
            calcCombinations(ans, candidates, target, curr, currIndex, currSum+candidates[currIndex]);
        }
        curr.pop_back();

        // pick the next index
        calcCombinations(ans, candidates, target, curr, currIndex+1, currSum);
    }
};