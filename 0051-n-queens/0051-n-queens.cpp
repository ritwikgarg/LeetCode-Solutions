class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');

        for (int i=0; i<n; i++) {
            board[i] = s;
        }

        solve(ans, board, 0);
        return ans;
    }

    void solve(vector<vector<string>>& ans, vector<string>& board, int currCol) {
        if (currCol == board.size()) {
            ans.push_back(board);
            return;
        }

        // Try to place a queen in each row of the current column
        for (int i=0; i<board.size(); i++) {
            // Check if it is safe to place a queen in given row
            board[i][currCol] = 'Q';
            if (isSafe(i, currCol, board)) {
                solve(ans, board, currCol+1);
            }
            board[i][currCol] = '.'; // backtrack
        }
    }

    bool isSafe(int row, int col, vector<string>& board) {
        // Check if a queen is on the same row or diagonal to the left of curr posn (since we are placing queens left to right)

        int copyRow = row-1;
        int copyCol = col-1;

        // Check top left diagnoal
        while (copyRow >=0 && copyCol >=0) {
            if (board[copyRow][copyCol] == 'Q') {
                return false;
            }
            copyRow--;
            copyCol--;
        }

        copyRow = row;
        copyCol = col-1;
        // Check left in the same row
        while (copyCol >= 0) {
            if (board[copyRow][copyCol] == 'Q') {
                return false;
            }
            copyCol--;
        }

        copyRow = row+1;
        copyCol = col-1;
        // Check bottom left diagonal
        while (copyRow < board.size() && copyCol >= 0) {
            if (board[copyRow][copyCol] == 'Q') {
                return false;
            }
            copyRow++;
            copyCol--;
        }

        return true;
    }
};