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
        queue<TreeNode*> q;
        vector<vector<int>> ans;

        if(!root) return ans;

        q.push(root);

        while(!q.empty()) {
            queue<TreeNode*> currLevelNodes;
            while (!q.empty()) {
                currLevelNodes.push(q.front());
                q.pop();
            }

            vector<int> temp;
            while(!currLevelNodes.empty()){
                TreeNode* currNode = currLevelNodes.front(); 
                temp.push_back(currNode->val);
                currLevelNodes.pop();
                if(currNode->left) q.push(currNode->left);
                if(currNode->right) q.push(currNode->right);
            }

            ans.push_back(temp);
        }
        return ans;
    }
};