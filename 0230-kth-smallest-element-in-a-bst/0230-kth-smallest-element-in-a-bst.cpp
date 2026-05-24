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
    int kthSmallest(TreeNode* root, int k) {
        // We will use a BST property: inorder traversal of BST results in sorted elements

        int count = 0;
        int ans = 0;
        if (!root) return 0;

        DFS(root, k, count, ans);
        return ans;
    }

    void DFS (TreeNode* node, int k, int& count, int& ans) {
        if (!node) return;

        DFS(node->left, k, count, ans);
        count++;
        if (count == k) ans = node->val;
        DFS(node->right, k, count, ans);
    }
};