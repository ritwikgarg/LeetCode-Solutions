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
    int ans = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        diameter(root);
        return ans;
    }

    int diameter(TreeNode* node) {
        if(node == nullptr)
            return 0;

        int leftDepth = diameter(node->left);
        int rightDepth = diameter(node->right);

        ans = max(ans, leftDepth + rightDepth);

        return 1+max(leftDepth, rightDepth);
    }
};