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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        levelorder(root, 0, ans);
        return ans;
    }

    void levelorder(TreeNode* node, int level, vector<vector<int>>& ans) {
        if (node == nullptr) {
            return;
        }

        // Check if curr node is the first node we have seen for this level
        if(level == ans.size()) {
            ans.push_back({});
        }
        ans[level].push_back(node->val);

        levelorder(node->left, level+1, ans);
        levelorder(node->right, level+1, ans);
    }
};