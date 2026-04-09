/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> hashset;
        while (head != nullptr) {
            if (hashset.contains(head)) {
                return head;
            }
            hashset.insert(head);
            head = head->next;
        }
        return nullptr;
    }
};