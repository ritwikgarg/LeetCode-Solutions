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
    ListNode* reverseList(ListNode* head) {
        ListNode* reverse = nullptr;
        reverseLL(head, reverse);
        return reverse;
    }

    void reverseLL(ListNode* head, ListNode*& reverse) {
        if (head == nullptr) {
            return;
        }

        ListNode* next = head->next;
        head->next = reverse;
        reverse = head;
        head = next;

        reverseLL(head, reverse);
    }
};