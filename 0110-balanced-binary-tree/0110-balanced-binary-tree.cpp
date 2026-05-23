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
    bool balanced = true;
    bool isBalanced(TreeNode* root) {
        checkBalance(root);
        return balanced;
    }

    int checkBalance(TreeNode* node) {
        if (node == nullptr)
            return 0;
        
        int leftDepth = checkBalance(node->left);
        int rightDepth = checkBalance(node->right);

        if (abs(rightDepth-leftDepth) > 1) balanced = false;

        return 1 + max(leftDepth, rightDepth);
    }
};