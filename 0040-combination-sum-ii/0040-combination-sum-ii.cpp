class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        findCombinations(ans, candidates, target, curr, 0, 0);
        return ans;
    }

    void findCombinations(vector<vector<int>>& ans, vector<int>& candidates, int target, vector<int>& curr, int currIndex, int currSum) {
        if (currSum >= target || currIndex == candidates.size()) {
            if (currSum == target) {
                ans.push_back(curr);
            }
            return;
        }

        curr.push_back(candidates[currIndex]);
        findCombinations(ans, candidates, target, curr, currIndex+1, currSum + candidates[currIndex]);
        curr.pop_back();

        int currValue = candidates[currIndex];
        int i = currIndex+1;
        while (i < candidates.size() && currValue == candidates[i]) {
            i++;
        }
        findCombinations(ans, candidates, target, curr, i, currSum);
    }
};