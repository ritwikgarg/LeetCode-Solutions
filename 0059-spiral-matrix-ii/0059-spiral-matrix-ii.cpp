class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int direction = 0; // 0-> right, 1-> down, 2-> left, 3-> up
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int count = 1;
        int startRow = 0;
        int endRow = n-1;
        int startCol = 0;
        int endCol = n-1;
        while (count <= (n*n)) {
            if (direction%4 == 0) {
                for (int j=startCol; j<=endCol; j++) {
                    ans[startRow][j] = count;
                    count++;
                }
                direction++;
                startRow++;
            }
            else if (direction%4 == 1) {
                for (int i = startRow; i<=endRow; i++) {
                    ans[i][endCol] = count;
                    count++;
                }
                direction++;
                endCol--;
            }
            else if (direction%4 == 2) {
                for (int j=endCol; j>=startCol; j--) {
                    ans[endRow][j] = count;
                    count++;
                }
                direction++;
                endRow--;
            }
            else if (direction%4 == 3) {
                for (int i= endRow; i>=startRow; i--) {
                    ans[i][startCol] = count;
                    count++;
                }
                direction++;
                startCol++;
            }
        }
        return ans;
    }
};