    class Solution {
    public:
        int largestRectangleArea(vector<int>& heights) {
            // Idea: traverse normally to calculate pse. Whenever an element is popped from the stack, it means
            // that the new element getting inserted is smaller than the current element. Hence the nse for the
            // element being popped is the element that is being pushed in. As well as, the pse of the element popped
            // is the element now on top of the stack. Using this, find the area.

            // In the end, if stack is not empty, it means each of those elements in the stack did not have a nse,
            // Hence, pop each element, element now on top would be pse and nse = n. Find area again. Return max.

            long long maxArea = 0;
            stack<int> monotonicStack;
            int n = heights.size();

            for (int i=0; i<n; i++) {
                long long area = 0;
                while (!monotonicStack.empty() && heights[monotonicStack.top()] > heights[i]) {
                    int nseIdx = i;
                    int height = heights[monotonicStack.top()];
                    monotonicStack.pop();
                    int pseIdx = (monotonicStack.empty()) ? -1 : monotonicStack.top();
                    area = height * 1LL * (nseIdx - pseIdx - 1);
                    maxArea = max(area, maxArea);
                }
                monotonicStack.push(i);
            }

            long long area = 0;
            while(!monotonicStack.empty()) {
                int height = heights[monotonicStack.top()];
                int nseIdx = n;
                monotonicStack.pop();
                int pseIdx = (monotonicStack.empty()) ? -1 : monotonicStack.top();
                area = height * 1LL * (nseIdx - pseIdx - 1);
                maxArea = max(area, maxArea);
            }
            return maxArea;
        }

    };