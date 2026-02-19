class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for (int i: nums) {
            if (minHeap.size() >= k) {
                if (minHeap.top() > i) {
                    // do nothing
                } else {
                    minHeap.pop();
                    minHeap.push(i);
                }
            } else {
                minHeap.push(i);
            }
        }
    }
    
    int add(int val) {
        if (minHeap.size() < k) {
            minHeap.push(val);
            return minHeap.top();
        } else {
            if (val > minHeap.top()) {
                minHeap.pop();
                minHeap.push(val);
                return minHeap.top();
            } else {
                return minHeap.top();
            }
        }
    }

private:
    priority_queue <int, vector<int>, greater<int>> minHeap;
    int k;

};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */