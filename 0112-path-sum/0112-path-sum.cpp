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
    bool pathFound = false;
    bool hasPathSum(TreeNode* root, int targetSum) {
        DFS(root, 0, targetSum);
        return pathFound;
    }

    void DFS(TreeNode* node, int runningSum, int targetSum) {
        if (!node || pathFound) return;

        runningSum += node->val;

        if (isLeaf(node) && runningSum == targetSum) {
            pathFound = true;
            return;
        }

        DFS(node->left, runningSum, targetSum);
        DFS(node->right, runningSum, targetSum);
    }

    bool isLeaf(TreeNode* node) {
        if (node != nullptr && node->left == nullptr && node->right == nullptr) return true;
        return false;
    }
};