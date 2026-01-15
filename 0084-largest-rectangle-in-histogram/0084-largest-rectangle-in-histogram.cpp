class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // Idea: maintain a pse and nse for each bar and using those indexes, calculate area
        vector<int> pseeIdx = prevSmallerOrEqualElementIndex(heights);
        vector<int> nseIdx = nextSmallerElementIndex(heights);

        int n = heights.size();

        int maxArea = 0;
        int area = 0;
        for (int i=0; i<n; i++) {
            area = heights[i] * (nseIdx[i] - pseeIdx[i] - 1);
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }

    vector<int> prevSmallerOrEqualElementIndex(vector<int>& nums) {
        stack<int> monotonicStack;
        int n = nums.size();
        vector<int> pseeIdx (n, 0);

        for (int i=0; i<n; i++) {
            while (!monotonicStack.empty() && nums[monotonicStack.top()] >= nums[i]) {
                monotonicStack.pop();
            }

            pseeIdx[i] = (monotonicStack.empty()) ? -1 : monotonicStack.top();
            monotonicStack.push(i);
        }

        return pseeIdx;
    }

    vector<int> nextSmallerElementIndex(vector<int>& nums) {
        stack<int> monotonicStack;
        int n = nums.size();
        vector<int> nseIdx (n, 0);

        for (int i=n-1; i>=0; i--) {
            while (!monotonicStack.empty() && nums[monotonicStack.top()] > nums[i]) {
                monotonicStack.pop();
            }
            nseIdx[i] = (monotonicStack.empty()) ? n : monotonicStack.top();
            monotonicStack.push(i);
        }
        
        return nseIdx;
    }

};