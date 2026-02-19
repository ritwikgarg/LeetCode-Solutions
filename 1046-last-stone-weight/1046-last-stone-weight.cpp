class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue <int> maxHeap;

        int n = stones.size();

        for (int i=0; i<n; i++) {
            maxHeap.push(stones[i]);
        }

        while (!maxHeap.empty()) {
            int x = maxHeap.top();
            maxHeap.pop();

            if (maxHeap.size() == 0) {
                return x;
            }

            int y = maxHeap.top();
            maxHeap.pop();

            //we know x >= y
            if (x > y) {
                maxHeap.push(x-y);
            } else {
                // don't do anything if they are equal
            }
         }

        return 0;
    }
};