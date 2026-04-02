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

        if (head == nullptr || head->next == nullptr) return;
        
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // slow now points to the middle of the linked list

        ListNode* second = slow->next;
        slow->next = nullptr;
        ListNode* reverseList = reverse(second);

        while (head != nullptr && reverseList != nullptr) {
            ListNode* tempHead = head->next;
            ListNode* tempRev = reverseList->next;

            head->next = reverseList;
            reverseList->next = tempHead;

            head = tempHead;
            reverseList = tempRev;
        }
    }

    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* next = curr->next; // save
            curr->next = prev;           // reverse
            prev = curr;                 // move prev
            curr = next;                 // move curr
        }

        return prev;
    }
};