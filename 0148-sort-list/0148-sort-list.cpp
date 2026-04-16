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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        
        ListNode* rightHalf = splitHalf(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(rightHalf);

        return merge(left, right);
    }

    ListNode* merge(ListNode* leftHalf, ListNode* rightHalf) {
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;

        while (leftHalf && rightHalf) {
            if (leftHalf->val < rightHalf->val) {
                tail->next = leftHalf;
                leftHalf = leftHalf->next;
            } else {
                tail->next = rightHalf;
                rightHalf = rightHalf->next;
            }
            tail = tail->next;
        }

        // Drain out remaining nodes
        while(leftHalf) {
            tail->next = leftHalf;
            leftHalf = leftHalf->next;
            tail = tail->next;
        }
        
        while(rightHalf) {
            tail->next = rightHalf;
            rightHalf = rightHalf->next;
            tail = tail->next;
        }

        return dummy->next;
    }

    ListNode* splitHalf(ListNode* head) {
        if (!head || !head->next) {
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* mid = slow->next;
        slow->next = nullptr;
        return mid;
    }
};