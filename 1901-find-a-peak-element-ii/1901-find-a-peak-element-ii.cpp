class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(); //no. of rows
        int n = mat[0].size(); //no. of cols

        int low = 0;
        int high = n-1;

        while (low <= high) {
            int mid = low + (high-low)/2;
            int maxIndex = rowIdxOfMaxElement(mat, m, mid); // Returns idx of 'row' of max element in 'mid' col.

            int left  = (mid == 0) ? INT_MIN : mat[maxIndex][mid - 1];
            int right = (mid == n - 1) ? INT_MIN : mat[maxIndex][mid + 1];

            if (mat[maxIndex][mid] > left && mat[maxIndex][mid]> right) {
                return {maxIndex, mid};
            } 
            else if (mat[maxIndex][mid] > left && mat[maxIndex][mid] < right) {
                low = mid+1;
            }
            else if (mat[maxIndex][mid] < left && mat[maxIndex][mid] > right) {
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
    return {-1,-1};
    }

    int rowIdxOfMaxElement(vector<vector<int>>& mat, int rows, int mid) {
        int maxElem = INT_MIN;
        int index = 0;
        for (int i=0; i<rows; i++) {
            if (mat[i][mid] > maxElem) {
                maxElem = mat[i][mid];
                index = i;
            }
        }
        return index;
    }
};