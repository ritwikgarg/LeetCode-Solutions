/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> currPath = {};
        DFS(root, 0, targetSum, currPath, ans);
        return ans;
    }

    void DFS(TreeNode* node, int runningSum, int targetSum, vector<int>& currPath, vector<vector<int>>& ans) {
        if (!node) return;

        currPath.push_back(node->val);
        runningSum += node->val;

        if (isLeaf(node) && runningSum == targetSum) {
            ans.push_back(currPath);
        }

        DFS(node->left, runningSum, targetSum, currPath, ans);
        DFS(node->right, runningSum, targetSum, currPath, ans);
        currPath.pop_back();
    }
 
    bool isLeaf(TreeNode* node) {
        if (node && !node->left && !node->right) return true;
        return false; 
    }
};