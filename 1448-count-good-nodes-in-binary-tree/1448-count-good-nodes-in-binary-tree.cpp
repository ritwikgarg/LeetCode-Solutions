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
    int goodNodes(TreeNode* root) {
        DFS(root, INT_MIN);
        return ans;
    }

    void DFS(TreeNode* node, int maxSoFar) {
        if (node == nullptr)
            return;
        
        if (node->val >= maxSoFar) {
            ++ans;
            maxSoFar = node->val;
        }

        DFS(node->left, maxSoFar);
        DFS(node->right, maxSoFar);
    }
};