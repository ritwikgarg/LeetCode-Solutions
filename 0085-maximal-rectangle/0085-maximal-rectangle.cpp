class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int maxArea = 0;

        vector<int> heights (cols, 0);
        for (int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                if (matrix[i][j] == '1') {
                    heights[j]+=1;
                } else {
                    heights[j] = 0;
                }
            }
            int area = maxAreaInHistogram(heights);
            maxArea = max(area, maxArea);
        }

        return maxArea;
    }

    int maxAreaInHistogram(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int maxArea = 0;

        for (int i=0; i<n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int currHeight = heights[st.top()];
                st.pop();
                int nseIdx = i;
                int pseIdx = st.empty() ? -1 : st.top();
                int area = (nseIdx - pseIdx - 1) * currHeight;
                maxArea = max(maxArea, area);
            }

            st.push(i);
        }

        while (!st.empty()) {
            int nseIdx = n;
            int currHeight = heights[st.top()];
            st.pop();
            int pseIdx = st.empty() ? -1 : st.top();
            int area = (nseIdx - pseIdx - 1) * currHeight;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};