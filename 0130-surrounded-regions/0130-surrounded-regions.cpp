class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        // Obs: we just need to identify 'O' on the boundary and treat those as source for DFS

        int checkRow[] = {0, n-1};
        int checkCol[] = {0, m-1};

        // Check first col and last col
        for (int j=0; j<2; j++) {
            int col = checkCol[j];
            for (int i=0; i<n; i++) {
                if ((board[i][col] == 'O' && !visited[i][col])) {
                    dfs(n, m, board, i, col, visited);
                }
            }
        }

        // Check first row and last row
        for (int i=0; i<2; i++) {
            int row = checkRow[i];
            for (int j=0; j<m; j++) {
                if ((board[row][j] == 'O' && !visited[row][j])) {
                    dfs(n, m, board, row, j, visited);
                }
            }
        }

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (visited[i][j] == 1) {
                    board[i][j] = 'O';
                } else {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void dfs(int n, int m, vector<vector<char>>& board, int row, int col, vector<vector<int>>& visited) {
        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, -1, 0, 1};
        visited[row][col] = 1;

        for (int i=0; i<4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow >= 0 && nrow < n && ncol >=0 && ncol < m && !visited[nrow][ncol] && board[nrow][ncol] == 'O') {
                dfs(n, m, board, nrow, ncol, visited);
            }
        }
    }
};