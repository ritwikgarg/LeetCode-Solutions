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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int alen = 0;
        int blen = 0;

        ListNode *tailA = headA;
        ListNode *tailB = headB;

        while (tailA) {
            alen++;
            tailA = tailA->next;
        }

        while (tailB) {
            blen++;
            tailB = tailB->next;
        }

        if (tailA != tailB) {
            return nullptr;
        }

        if (alen < blen) {
            int diff = blen-alen;
            ListNode* astart = headA;
            ListNode* bstart = headB;
            while (diff > 0) {
                diff--;
                bstart = bstart->next;
            }

            while (astart && bstart) {
                if (astart == bstart) {
                    return astart;
                }
                astart = astart->next;
                bstart = bstart->next;
            }
        } else {
            int diff = alen-blen;
            ListNode* astart = headA;
            ListNode* bstart = headB;
            while (diff > 0) {
                diff--;
                astart = astart->next;
            }

            while (astart && bstart) {
                if (astart == bstart) {
                    return astart;
                }
                astart = astart->next;
                bstart = bstart->next;
            }
        }

        return nullptr;
    }
};