/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if (!root) return ans;

        unordered_map <TreeNode*, TreeNode*> parent;

        DFS(root, parent);

        unordered_set <TreeNode*> visited;

        queue<TreeNode*> q;
        q.push(target);
        visited.insert(target);

        int dist = 0;

        while(!q.empty()) {
            int levelSize = q.size();

            if (dist == k) {
                while (!q.empty()) {
                    ans.push_back(q.front()->val);
                    q.pop();
                }
                return ans;
            }

            for (int i=0; i<levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left && !visited.count(node->left)) {
                    visited.insert(node->left);
                    q.push(node->left);
                }

                if (node->right && !visited.count(node->right)) {
                    visited.insert(node->right);
                    q.push(node->right);
                }

                if (parent[node] && !visited.count(parent[node])) {
                    visited.insert(parent[node]);
                    q.push(parent[node]);
                }
            }
            dist++;
        }

        return ans;
    }


    void DFS(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {
        if (!root) return;

        if (root->left) {
            parent[root->left] = root;
            DFS(root->left, parent);
        }

        if (root->right) {
            parent[root->right] = root;
            DFS(root->right, parent);
        }
    }
};