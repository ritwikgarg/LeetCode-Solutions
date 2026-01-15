class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<vector<int>> prefixMatrix(rows, vector<int>(cols));

        for (int j=0; j<cols; j++) {
            int sum = 0;
            for (int i=0; i<rows; i++) {
                if (matrix[i][j] == '1') {
                    sum += 1;
                } else {
                    sum = 0;
                }
                prefixMatrix[i][j] = sum;
            }
        }

        int maxArea = 0;
        int area = 0;
        for (int i=0; i<rows; i++) {
            area = maxAreaInHistogram(prefixMatrix[i]);
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }

    int maxAreaInHistogram(vector<int> nums) {
        int n = nums.size();
        stack<int> st;
        int maxArea = 0;

        for (int i=0; i<n; i++) {
            int area = 0;
            while (!st.empty() && nums[st.top()] > nums[i]) {
                int nseIdx = i;
                int height = nums[st.top()];
                st.pop();
                int pseIdx = (st.empty()) ? -1 : st.top();
                area = height * (nseIdx - pseIdx - 1);
                maxArea = max (area, maxArea);
            }
            st.push(i);
        }

        // Elements that don't have a nseIdx -> assume nseIdx = n 
        int area = 0;
        while (!st.empty()) {
            int nseIdx = n;
            int height = nums[st.top()];
            st.pop();
            int pseIdx = (st.empty()) ? -1 : st.top();
            area = height * (nseIdx - pseIdx - 1);
            maxArea = max(area, maxArea);
        }

        return maxArea;
    }
};