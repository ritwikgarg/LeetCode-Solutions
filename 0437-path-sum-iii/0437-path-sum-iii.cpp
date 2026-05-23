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
    int pathSum(TreeNode* root, int targetSum) {
        int count = 0;
        DFS(root, 0, targetSum, count, true);
        return count;
    }

    void DFS(TreeNode* node, long long runningSum, int targetSum, int& count, bool canStartNew) {
        if (!node) return;

        runningSum += node->val;

        if (runningSum == targetSum) {
            count++;
        }

        // Continue the current path
        DFS(node->left, runningSum, targetSum, count, false);
        DFS(node->right, runningSum, targetSum, count, false);

        // Only one type of call is allowed to start fresh paths from children.
        // This prevents duplicate restarts.
        if (canStartNew) {
            DFS(node->left, 0, targetSum, count, true);
            DFS(node->right, 0, targetSum, count, true);
        }
    }
};