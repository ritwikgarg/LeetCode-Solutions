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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;

        if(!root) return ans;
        TreeNode* curr = root;
        TreeNode* lastVisited = nullptr;

        while(!st.empty() || curr) {
            while(curr) {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();

            if (curr->right != nullptr && lastVisited != curr->right) {
                curr = curr->right;
            } else {
                lastVisited = curr;
                ans.push_back(curr->val);
                st.pop();
                curr = nullptr;
            }
        }

        return ans;
    }
};