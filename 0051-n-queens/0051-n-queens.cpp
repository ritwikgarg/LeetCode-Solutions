class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');

        vector<int> leftRow (n, 0);
        vector<int> topDiagonal (2*n-1, 0);
        vector<int> bottomDiagonal (2*n-1, 0);

        for (int i=0; i<n; i++) {
            board[i] = s;
        }

        solve(ans, board, 0, leftRow, topDiagonal, bottomDiagonal);
        return ans;
    }

    void solve(vector<vector<string>>& ans, vector<string>& board, int currCol, vector<int>& leftRow, vector<int>& topDiagonal, vector<int>& bottomDiagonal) {
        if (currCol == board.size()) {
            ans.push_back(board);
            return;
        }

        // Try to place a queen in each row of the current column
        for (int i=0; i<board.size(); i++) {
            // Check if it is safe to place a queen in given row
            if (leftRow[i] != 1 && bottomDiagonal[i+currCol] != 1 && topDiagonal[(board.size()-1) + (currCol - i)] != 1) {
                board[i][currCol] = 'Q';
                leftRow[i] = 1;
                bottomDiagonal[i+currCol] = 1;
                topDiagonal[(board.size()-1) + (currCol - i)] = 1;

                solve(ans, board, currCol+1, leftRow, topDiagonal, bottomDiagonal);

                // backtrack
                board[i][currCol] = '.';
                leftRow[i] = 0;
                bottomDiagonal[i+currCol] = 0;
                topDiagonal[(board.size()-1) + (currCol - i)] = 0;
            }
        }
    }
};