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
    int amountOfTime(TreeNode* root, int start) {
        if (!root) return 0;

        unordered_map<TreeNode*, TreeNode*> parent; // stores child, parent

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();

            for (int i=0; i<levelSize; i++) {

                TreeNode* currNode = q.front();
                q.pop();

                if (currNode->left) {
                    parent[currNode->left] = currNode;
                    q.push(currNode->left);
                }

                if (currNode->right) {
                    parent[currNode->right] = currNode;
                    q.push(currNode->right);
                }
            }
        }

        TreeNode* infectedNode = findNode(root, start);

        return bfs(infectedNode, parent);
    }

    int bfs(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {
        unordered_set<TreeNode*> visited;
        queue<TreeNode*> q;
        q.push(root);
        visited.insert(root);
        int time = -1;

        while (!q.empty()) {
            int levelSize = q.size();

            for(int i=0; i<levelSize; i++) {
                TreeNode* currNode = q.front();
                q.pop();

                if(currNode->left && !visited.count(currNode->left)) {
                    visited.insert(currNode->left);
                    q.push(currNode->left);
                } 
                if(currNode->right && !visited.count(currNode->right)) {
                    visited.insert(currNode->right);
                    q.push(currNode->right);
                }
                if(parent[currNode] && !visited.count(parent[currNode])) {
                    visited.insert(parent[currNode]);
                    q.push(parent[currNode]);
                }

            }
            time++;
        }
        return time;
    }

    TreeNode* findNode(TreeNode* node, int target) {
        if (!node) return nullptr;

        if (node->val == target) return node;

        TreeNode* leftResult = findNode(node->left, target);
        if (leftResult) return leftResult;

        TreeNode* rightResult = findNode(node->right, target);
        if (rightResult) return rightResult;

        return nullptr;
    }
};