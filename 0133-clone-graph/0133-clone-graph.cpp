/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map <Node*, Node*> mp; // Stores mapping between old and new nodes
        return dfs(node, mp);
    }

    Node* dfs(Node* node, unordered_map<Node*, Node*>& mp) {
        if (!node) return nullptr;

        vector<Node*> neighbors;
        Node* clone = new Node(node->val);
        mp[node] = clone;

        for (auto it:node->neighbors) {
            if (mp.find(it) == mp.end()) {
                neighbors.push_back(dfs(it, mp));
            } else {
                neighbors.push_back(mp[it]);
            }
        }

        clone->neighbors = neighbors;
        return clone;
    }
};