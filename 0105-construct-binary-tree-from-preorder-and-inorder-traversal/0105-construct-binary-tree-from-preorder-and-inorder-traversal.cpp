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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> inorderMap; // Stores node val -> index in inorder array

        for (int i=0; i< inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }

        TreeNode* root = buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inorderMap);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int,int>& inorderMap) {

        if (preStart > preEnd || inStart > inEnd) return nullptr;

        TreeNode* root = new TreeNode(preorder[preStart]);

        int rootIndex = inorderMap[root->val];
        int numsOnLeft = rootIndex - inStart;

        root->left = buildTree(preorder, preStart + 1, preStart + numsOnLeft, inorder, inStart, rootIndex-1, inorderMap);

        root->right = buildTree(preorder, preStart + numsOnLeft + 1, preEnd, inorder, rootIndex+1, inEnd, inorderMap);

        return root;
    }
};