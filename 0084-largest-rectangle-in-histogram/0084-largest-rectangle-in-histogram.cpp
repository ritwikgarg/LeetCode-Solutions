class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // Idea: find the pseIdx and nseIdx, and using there difference as the width, calculate area

        int n = heights.size();

        vector<int> pseIdx = prevSmallerElement(heights, n);
        vector<int> nseIdx = nextSmallerElement(heights, n);

        int maxArea = 0;

        for (int i=0; i<n; i++) {
            int area = (nseIdx[i] - pseIdx[i] - 1) * heights[i];
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }

    vector<int> prevSmallerElement(vector<int>& heights, int n) {
        stack<int> st;
        vector<int> pseIdx (n,0);

        for(int i=0; i<n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                st.pop();
            }
            pseIdx[i] = st.empty()? -1 : st.top();

            st.push(i);
        }

        return pseIdx;
    }

    vector<int> nextSmallerElement(vector<int>& heights, int n) {
        stack<int> st;
        vector<int> nseIdx (n, 0);

        for(int i=n-1; i>=0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            nseIdx[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        return nseIdx;
    }
};