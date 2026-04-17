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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k==1) {
            return head;
        }

        ListNode* temp = head;
        ListNode* newHead = nullptr;
        ListNode* prevPartTail = nullptr;

        while (temp) {
            // Step 1: Check if k nodes exist
            ListNode* groupHead = temp;
            ListNode* groupTail = temp;
            int count = 1;

            while (count<k && groupTail) {
                groupTail = groupTail->next;
                count++;
            }

            if (!groupTail) {
                // less than k nodes left
                if (prevPartTail)
                    prevPartTail->next = groupHead;
                break;
            }

            ListNode* nextGroupHead = groupTail->next;

            // cut group
            groupTail->next = nullptr;

            // Step 2: reverse group
            reverseList(groupHead, groupTail);

            // Step 3: connect previous part
            if (!newHead)
                newHead = groupHead;

            if (prevPartTail)
                prevPartTail->next = groupHead;
            
            // Step 4: reconnect tail to next group
            groupTail->next = nextGroupHead;

            prevPartTail = groupTail;
            temp = nextGroupHead;
        }
        return newHead ? newHead : head;
    }

    void reverseList(ListNode*& head, ListNode*& tail) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        tail = head;
        head = prev;
    }
};