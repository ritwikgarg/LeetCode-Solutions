class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node dummy(0);
        Node* copiedTail = &dummy;

        // Step 1: Insert copied nodes between original nodes
        Node* original = head;

        while (original) {
            Node* copied = new Node(original->val);

            Node* originalNext = original->next;

            original->next = copied;
            copied->next = originalNext;

            original = originalNext;
        }

        // Step 2: Assign random pointers
        original = head;

        while (original && original->next) {
            Node* copied = original->next;

            copied->random =
                original->random
                ? original->random->next
                : nullptr;

            original = copied->next;
        }

        // Step 3: Separate copied list and restore original
        original = head;

        while (original && original->next) {
            Node* copied = original->next;

            Node* nextOriginal = copied->next;

            copiedTail->next = copied;
            copiedTail = copied;

            copied->next = nullptr;

            original->next = nextOriginal;

            original = nextOriginal;
        }

        return dummy.next;
    }
};