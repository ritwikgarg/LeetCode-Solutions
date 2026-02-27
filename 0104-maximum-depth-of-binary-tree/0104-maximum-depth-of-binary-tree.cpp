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
    int maxDepth(TreeNode* root) {
        return findDepth(root, 0);
    }

    int findDepth(TreeNode* node, int currlevel) {
        if (node == nullptr) {
            return currlevel;
        }
        if (node->left == nullptr && node->right == nullptr) {
            return currlevel+1;
        }

        int leftDepth = currlevel;
        int rightDepth = currlevel;
        if (node->left) {
            leftDepth = findDepth(node->left, currlevel+1);
        }
        if (node->right) {
            rightDepth = findDepth(node->right, currlevel+1);
        }

        return max(leftDepth, rightDepth);
    }
};