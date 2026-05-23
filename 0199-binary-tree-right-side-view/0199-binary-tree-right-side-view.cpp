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
        queue<TreeNode*> q;
        vector<vector<int>> bfs;
        vector<int> ans;
        if (!root) return ans;

        q.push(root);

        while (!q.empty()) {
            int qsize = q.size();
            vector<int> level = {};
            for (int i=1; i<=qsize; i++) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            bfs.push_back(level);
        }

        for (int i=0; i<bfs.size(); i++) {
            int levelSize = bfs[i].size();
            ans.push_back(bfs[i][levelSize-1]);
        }

        return ans;
    }
};