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
    int widthOfBinaryTree(TreeNode* root) {
        int maxWidth = 0;
        if (!root) return maxWidth;

        queue<pair<TreeNode*, int>> q;
        q.push({root,0});

        while(!q.empty()) {
            int levelSize = q.size();

            int minIndex = q.front().second;
            int first = 0;
            int last = 0;
            for(int i=0; i<levelSize; i++) {
                pair<TreeNode*, int> p = q.front();
                int currIndex = p.second-minIndex;
                q.pop();
                if (i==0) first = currIndex;
                if (i==levelSize-1) last = currIndex;

                if (p.first->left) q.push({p.first->left, (long long) 2*(currIndex) + 1});
                if (p.first->right) q.push({p.first->right, (long long) 2*(currIndex) + 2});

            }
            maxWidth = max(maxWidth, last-first+1);
        }
        return maxWidth;
    }
};