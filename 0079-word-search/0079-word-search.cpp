class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        if (word.length() > rows*cols) return false;

        for (int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                if(exploreBoard(board, word, i, j, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool exploreBoard(vector<vector<char>>& board, string& word, int currRow, int currCol, int currIndex, int prevRow, int prevCol) {
        if (currIndex == word.size()) {
            return true;
        }
        if (board[currRow][currCol] == word[currIndex]) {
            if ((currRow == board.size() - 1 && currCol == board[0].size()-1 && currIndex == word.size()-1) || (currRow == 0 && currCol == 0 && currIndex == word.size()-1)) {
                return true;
            }
            if (currRow - 1 >= 0) {
                if (!(currRow-1 == prevRow && currCol == prevCol)) {
                    if (exploreBoard(board, word, currRow-1, currCol, currIndex+1, currRow, currCol)) {
                        return true;
                    } // Search top
                }
            }
            if (currRow + 1 < board.size()) {
                if (!(currRow+1 == prevRow && currCol == prevCol)) {
                    if (exploreBoard(board, word, currRow+1, currCol, currIndex+1, currRow, currCol)) {
                        return true;
                    } // Search bottom
                }
            }
            if (currCol -1 >= 0) {
                if (!(currRow == prevRow && currCol-1 == prevCol)) {
                    if (exploreBoard(board, word, currRow, currCol-1, currIndex+1, currRow, currCol)) {
                        return true;
                    } // Search left
                }
            }
            if (currCol + 1 < board[0].size()) {
                if (!(currRow == prevRow && currCol+1 == prevCol)) {
                    if (exploreBoard(board, word, currRow, currCol+1, currIndex+1, currRow, currCol)) {
                        return true;
                    } // Search right
                }
            }
        }

        return false;
    }
};