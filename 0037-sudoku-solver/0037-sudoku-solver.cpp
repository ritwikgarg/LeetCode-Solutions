class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        bool row[9][10] = {false};
        bool col[9][10] = {false};
        bool box[9][10] = {false};

        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board.size(); j++) {
                char ch = board[i][j];
                if (ch != '.') {
                    int d = ch-'0';
                    row[i][d] = true;
                    col[j][d] = true;
                    box[(i/3)*3 + j/3][d] = true;
                }
            }
        }

        solve(board, row, col, box);
    }

    bool solve(vector<vector<char>>& board, bool (&row)[9][10], bool (&col)[9][10], bool (&box)[9][10]) {

        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board.size(); j++) {
                char ch = board[i][j];
                if (ch == '.') {
                    for (int d=1; d<=9; d++) {
                        if (checkIfPossible(board, i, j, d, row, col, box)) {
                            board[i][j] = char('0'+d);
                            row[i][d] = col[j][d] = box[(i/3)*3 + (j/3)][d] = true;

                            if (solve(board, row, col, box)) return true;

                            // backtrack
                            board[i][j] = '.';
                            row[i][d] = col[j][d] = box[(i/3)*3 + (j/3)][d] = false;
                        } 
                    }
                    return false;  // no digit worked for this empty cell
                }
            }
        }

        return true;  // no empty cells => solved
    }

    bool checkIfPossible(vector<vector<char>>& board, int rowNo, int colNo, int d, bool (&row)[9][10], bool (&col)[9][10], bool (&box)[9][10]) {
        // Check same row
        if (row[rowNo][d]) {
            return false;
        }
        // Check same col
        if (col[colNo][d]) {
            return false;
        }

        // Check same box
        if (box[(rowNo/3)*3 + (colNo/3)][d]) {
            return false;
        }

        return true;
    }
};