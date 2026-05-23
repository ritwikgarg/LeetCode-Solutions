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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;

        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);

        while(!q.empty()) {
            int levelSize = q.size();

            TreeNode* leftNode = q.front();
            q.pop();

            TreeNode* rightNode = q.front();
            q.pop();

            if (!leftNode && !rightNode) continue;

            if (!leftNode || !rightNode) return false;

            if (leftNode->val != rightNode->val) return false;

            q.push(leftNode->left);
            q.push(rightNode->right);

            q.push(leftNode->right);
            q.push(rightNode->left);
        }
        return true;
    }
};