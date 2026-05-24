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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        if (root->val == key) {
            return helper(root);
        }

        TreeNode* curr = root;

        while (curr) {
            if (curr->val > key) {
                if (curr->left && curr->left->val == key) {
                    curr->left = helper(curr->left);
                    break;
                } else {
                    curr = curr->left;
                }
            } else {
                if (curr->right && curr->right->val == key) {
                    curr->right = helper(curr->right);
                    break;
                } else {
                    curr = curr->right;
                }
            }
        }

        return root;
    }

    TreeNode* helper(TreeNode* node) {
        if (!node->right) return node->left;

        if (!node->left) return node->right;

        TreeNode* nodeToAttachRightSubTreeTo = findLastRight(node->left);

        nodeToAttachRightSubTreeTo->right = node->right;
        return node->left;
    }

    TreeNode* findLastRight(TreeNode* node) {
        if (!node) return nullptr;

        if (!node->right) return node;

        return findLastRight(node->right);
    }
};