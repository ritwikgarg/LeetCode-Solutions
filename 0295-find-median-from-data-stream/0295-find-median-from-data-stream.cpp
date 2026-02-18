class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        updateMedian(num);
    }
    
    double findMedian() {
        return median;
    }

private:
    priority_queue <int, vector<int>, greater<int>> minHeap;
    priority_queue <int> maxHeap;
    double median = -1;

    void updateMedian(int element) {
        switch(signum(maxHeap.size(), minHeap.size())) {
            case 0: // Both maxHeap and minHeap have the same size (n)
                if (element > median) {
                    minHeap.push(element); // minHeap now has n+1 elements -> total no. of elements is odd
                    median = (double) minHeap.top(); // median is element on top of min heap
                } else {
                    maxHeap.push(element); // maxHeap now has n+1 elements -> total no. of elements is odd
                    median = (double) maxHeap.top(); // median is element on top of max heap
                }
                break;
            
            case 1: // maxHeap has n+1 elements, minHeap has n elements
                if (element > median) {
                    minHeap.push(element); // minHeap has n+1 elements
                    median = (double)(maxHeap.top() + minHeap.top())/2;
                } else {
                    // Should ideally push to maxheap but we can't let maxHeap have n+2 elements
                    // So pop from maxHeap, put into minHeap and then insert new element into maxHeap
                    minHeap.push(maxHeap.top()); // minHeap has n+1 elements
                    maxHeap.pop();
                    maxHeap.push(element); // maxHeap has n+1 elements
                    median = (double)(maxHeap.top() + minHeap.top())/2;
                }
                break;

            case -1: // maxHeap has n elements, minHeap has n+1 elements
                if (element > median) {
                    // Should ideally push to minHeap but we can't let minHeap have n+2 elements
                    // So pop from minHeap, put into maxHeap and then insert new element into minHeap
                    maxHeap.push(minHeap.top());
                    minHeap.pop();
                    minHeap.push(element);
                    median = (double)(maxHeap.top() + minHeap.top())/2;
                } else {
                    maxHeap.push(element);
                    median = (double)(maxHeap.top() + minHeap.top())/2;
                }
                break;

        }
    }

    int signum(int a, int b) {
        if (a == b) return 0;
        else if (a > b) return 1;
        else return -1;
    }

};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */