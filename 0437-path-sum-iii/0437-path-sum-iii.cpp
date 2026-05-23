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
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefixSum;
        prefixSum[0] = 1;
        return DFS(root, 0, targetSum, prefixSum);
    }

    int DFS(TreeNode* node, long long currSum, int targetSum, unordered_map<long long, int>& prefixSum) {
        if (!node) return 0;

        int count = 0;

        currSum += (long long) node->val;
        count += prefixSum[currSum - targetSum];

        prefixSum[currSum]++;

        count += DFS(node->left, currSum, targetSum, prefixSum);
        count += DFS(node->right, currSum, targetSum, prefixSum);

        prefixSum[currSum]--;

        return count;
    }
};