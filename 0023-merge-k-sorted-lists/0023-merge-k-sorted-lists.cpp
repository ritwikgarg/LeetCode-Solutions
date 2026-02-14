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

class compare {
    public:
        bool operator() (ListNode* a, ListNode* b) {
            return (a->val > b->val);
        }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue <ListNode*, vector<ListNode*>, compare> minHeap;

        int k = lists.size();

        if (k == 0) {
            return nullptr;
        }

        // Insert the first element in all the k lists into the min heap
        for (int i=0; i<k; i++) {
            if (lists[i] != nullptr) {
                minHeap.push(lists[i]);
            }
        }

        // Until min heap is not empty, pop from top of min heap and then push into it from the same LL that we popped out of
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        while (!minHeap.empty()) {

            ListNode* top = minHeap.top();
            minHeap.pop();

            if (top->next != nullptr) {
                minHeap.push(top->next);
            }

            if (head == nullptr) { // answer LL is empty
                head = top;
                tail = top;
            }
            else { // insert at LL end
                tail->next = top;
                tail = top;
            }
        }

        return head;
    }
};