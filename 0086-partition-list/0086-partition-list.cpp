/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *small = new ListNode();
        ListNode *large = new ListNode();
        ListNode *smallTail = small;
        ListNode *largeTail = large;

        ListNode *curr = head;
        while(curr != nullptr) {
            ListNode *temp = curr->next;
            curr->next = nullptr;
            if (curr->val < x) {
                smallTail->next = curr;
                smallTail = curr;
            } else {
                largeTail->next = curr;
                largeTail = curr;
            }
            curr = temp;
        }

        smallTail->next = large->next;
        largeTail->next = nullptr;
        return small->next;
    }
};