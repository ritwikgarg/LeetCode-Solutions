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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* reverse = nullptr;

        while(slow != nullptr) {
            ListNode* next = slow->next;
            slow->next = reverse;
            reverse = slow;
            slow = next;
        }

        ListNode* tempHead = head;
        ListNode* tempRev = reverse;
        while (tempHead!=nullptr && tempRev!=nullptr) {
            if (tempHead->val == tempRev->val) {
                tempHead = tempHead->next;
                tempRev = tempRev->next;
            } else {
                return false;
            }
        }
        return true;
    }
};