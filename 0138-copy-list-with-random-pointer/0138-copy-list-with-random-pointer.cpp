/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> copyMap;
        Node dummy(0);
        Node* tail = &dummy;

        Node* curr = head;

        while(curr) {
            Node* newNode = new Node(curr->val);
            copyMap[curr] = newNode;

            tail->next = newNode;
            tail = newNode;

            curr = curr->next;
        }

        Node* oldCurr = head;
        Node* newCurr = dummy.next;

        while(oldCurr) {
            newCurr->random = oldCurr->random? copyMap[oldCurr->random]: nullptr;
            oldCurr = oldCurr->next;
            newCurr = newCurr->next;
        }

        return dummy.next;
    }
};