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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> traversal;
        inorder(root, traversal);

        int len = traversal.size();
        TreeNode* newRoot = buildTree(0, len-1, traversal);
        return newRoot;
    }

    TreeNode* buildTree(int startIndex, int endIndex, vector<int>& traversal) {
        if (startIndex > endIndex || startIndex < 0 || endIndex > traversal.size()-1) return nullptr;
        int midIndex = (startIndex + endIndex)/2;

        TreeNode* root = new TreeNode(traversal[midIndex]);

        root->left = buildTree(startIndex, midIndex-1, traversal);
        root->right = buildTree(midIndex+1, endIndex, traversal);

        return root;
    }

    void inorder(TreeNode* node, vector<int>& traversal) {
        if (!node) return;

        inorder(node->left, traversal);
        traversal.push_back(node->val);
        inorder(node->right, traversal);
    }
};