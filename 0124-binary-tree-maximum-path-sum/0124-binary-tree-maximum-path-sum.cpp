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
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        findMaxSum(root, &maxSum);
        return maxSum;
    }

    int findMaxSum(TreeNode* node, int* maxSum) {
        if (node == nullptr)
            return 0;
        
        int leftMax = findMaxSum(node->left, maxSum);
        int rightMax = findMaxSum(node->right, maxSum);

        *maxSum = max(*maxSum, node->val + leftMax + rightMax);

        int currSum = node->val + max(leftMax, rightMax);
        return currSum > 0 ?  currSum : 0;
    }
};