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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map <int, int> inorderMap;

        for (int i=0; i<inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }

        return buildTree (inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, inorderMap);
    }

    TreeNode* buildTree(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd, unordered_map<int, int>& inorderMap) {

        if (inStart > inEnd || postStart > postEnd) return nullptr;

        TreeNode* root = new TreeNode(postorder[postEnd]);

        int rootIndex = inorderMap[root->val];
        int numsOnLeft = rootIndex - inStart;

        root->left = buildTree(inorder, inStart, rootIndex-1, postorder, postStart, postStart + numsOnLeft - 1, inorderMap);

        root->right = buildTree(inorder, rootIndex+1, inEnd, postorder, postStart + numsOnLeft, postEnd - 1, inorderMap);

        return root;
    }
};