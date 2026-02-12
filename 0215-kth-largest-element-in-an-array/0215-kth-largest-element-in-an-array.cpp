class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Build a max-heap of the first k elements
        vector<int> heap (nums.begin(), nums.begin() + k);
        for (int i=k/2 - 1; i>=0; i--) {
            heapify(heap, heap.size(), i);
        }

        for (int i=k; i<nums.size(); i++) {
            if (nums[i] > heap[0]) { // Compare elements from k to n-1, with top of max heap
                heap[0] = nums[i];
                heapify(heap, k, 0);
            }
        }

        return heap[0];
    }

    void heapify(vector<int>& nums, int n, int i) {
        int smallest = i;
        int leftChild = 2*i + 1;
        int rightChild = 2*i + 2;

        if (leftChild < n && nums[leftChild] < nums[smallest]) {
            smallest = leftChild;
        }
        if (rightChild < n && nums[rightChild] < nums[smallest]) {
            smallest = rightChild;
        }

        if (smallest == i) {
            return;
        }

        swap(nums[smallest], nums[i]);
        heapify(nums, n, smallest);
    }

};