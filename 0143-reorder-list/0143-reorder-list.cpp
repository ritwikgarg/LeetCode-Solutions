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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != nullptr && fast->next != nullptr) {
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* curr = slow->next;
        ListNode* prev = nullptr;
        slow->next = nullptr;

        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        ListNode* reverse = prev;

        while (head != nullptr && reverse != nullptr) {
            ListNode* tempHead = head->next;
            ListNode* tempRev = reverse->next;
            head->next = reverse;
            reverse->next = tempHead;
            head = tempHead;
            reverse = tempRev;
        }



    }
};