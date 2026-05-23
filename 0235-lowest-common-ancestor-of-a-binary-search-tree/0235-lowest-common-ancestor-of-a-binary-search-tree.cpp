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
    bool foundNode = false;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> p_parents;
        vector<TreeNode*> q_parents;

        findNode(root, p, p_parents);
        foundNode = false;
        findNode(root, q, q_parents);

        for (auto node : p_parents) {
            cout << node->val;
        }
        cout << endl;
        
        for (auto node : q_parents) {
            cout << node->val;
        }

        int plen = p_parents.size();
        int qlen = q_parents.size();

        for(int i=plen-1; i>=0; i--) {
            for (int j=qlen-1; j>=0; j--) {
                if (p_parents[i] == q_parents[j]) {
                    return p_parents[i];
                }
            }
        }

        return nullptr;
    }

    void findNode(TreeNode* root, TreeNode* node, vector<TreeNode*>& parents) {
        if (root == nullptr || foundNode) return;
        parents.push_back(root);
        if (root == node) {
            foundNode = true;
            return;
        }

        findNode(root->left, node, parents);
        findNode(root->right, node, parents);
        if (!foundNode) parents.pop_back();
    }
};