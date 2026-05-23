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
    bool isSubTree = false;
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        DFS(root, subRoot);
        return isSubTree;
    }

    void DFS(TreeNode* node, TreeNode* subTree) {
        if (node == nullptr || isSubTree)
            return;
        
        if (sameTree(node, subTree)) {
            isSubTree = true;
            return;
        } 

        DFS(node->left, subTree);
        DFS(node->right, subTree);
    }

    bool sameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;
        if (p->val != q->val) return false;

        if (!sameTree(p->left, q->left)) return false;
        if (!sameTree(p->right, q->right)) return false;

        return true;
    }
};