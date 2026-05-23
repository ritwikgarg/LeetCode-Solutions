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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        BFS(root, 0, ans);
        return ans;
    }

    void BFS(TreeNode* node, int depth, vector<int>& ans) {
        if (node == nullptr) return;

        // First node seen at this depth is the rightmost one
        if (depth == ans.size()) {
            ans.push_back(node->val);
        }

        BFS(node->right, depth+1, ans);
        BFS(node->left, depth+1, ans);
    }
};