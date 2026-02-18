struct Node {
    int row;
    int col;
    int value;

    Node() : row(-1), col(-1), value(-1) {}

    Node(int row, int col, int value) {
        this->row = row;
        this->col = col;
        this->value = value;
    }
};

class compare {
public:
    bool operator()(Node* a, Node* b) {
        return (a->value > b->value);
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {

        int rows = nums.size();

        priority_queue<Node*, vector<Node*>, compare> minHeap;

        int maxElem = INT_MIN;

        // Push first element from each list
        for (int i = 0; i < rows; i++) {
            minHeap.push(new Node(i, 0, nums[i][0]));
            maxElem = max(maxElem, nums[i][0]);
        }

        int rangeStart = 0;
        int rangeEnd = 0;
        int minRange = INT_MAX;

        while (!minHeap.empty()) {

            Node* minNode = minHeap.top();
            minHeap.pop();

            int currMin = minNode->value;

            // Check current range
            if (maxElem - currMin < minRange) {
                minRange = maxElem - currMin;
                rangeStart = currMin;
                rangeEnd = maxElem;
            }

            int currRow = minNode->row;
            int currCol = minNode->col;

            // Move forward in same row
            if (currCol + 1 < nums[currRow].size()) {

                int nextVal = nums[currRow][currCol + 1];
                maxElem = max(maxElem, nextVal);

                minHeap.push(new Node(currRow, currCol + 1, nextVal));

            } else {
                break;  // one list exhausted
            }
        }

        return {rangeStart, rangeEnd};
    }
};