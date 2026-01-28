class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> visited (rows, vector<bool> (cols, false));

        for (int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                if (dfs(board, word, i, j, 0, visited, rows, cols)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string& word, int currRow, int currCol, int currIndex, vector<vector<bool>>& visited, int rows, int cols) {
        if (currIndex == word.size()) {
            return true;
        } 

        if (currRow < 0 || currRow >= rows || currCol < 0 || currCol >= cols || board[currRow][currCol] != word[currIndex] ||visited[currRow][currCol] == true) {
            return false;
        }

        visited[currRow][currCol] = true;
        bool res = dfs(board, word, currRow+1, currCol, currIndex+1, visited, rows, cols ) || 
        dfs(board, word, currRow-1, currCol, currIndex+1, visited, rows, cols ) ||
        dfs(board, word, currRow, currCol+1, currIndex+1, visited, rows, cols ) ||
        dfs(board, word, currRow, currCol-1, currIndex+1, visited, rows, cols );

        visited[currRow][currCol] = false;

        return res;
    }
};