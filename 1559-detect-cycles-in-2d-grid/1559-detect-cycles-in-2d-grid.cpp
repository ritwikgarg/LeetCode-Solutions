class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (!visited[i][j]) {
                    if (bfs(m, n, i, j, grid, visited)) return true;
                }
            }
        }
        return false;
    }

    bool bfs(int m, int n, int row, int col, vector<vector<char>>& grid, vector<vector<int>>& visited) {
        queue<pair<pair<int, int>, pair<int, int>>> q;
        // {{current row, current col}, {parent row, parent col}}
        q.push({{row, col}, {-1, -1}});
        visited[row][col] = 1;

        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, -1, 0, 1};

        while(!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int parentR = q.front().second.first;
            int parentC = q.front().second.second;
            q.pop();

            for (int i=0; i<4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if (nrow>=0 && nrow<m && ncol>=0 && ncol<n && (grid[r][c] == grid[nrow][ncol])) {
                    if (!visited[nrow][ncol]) {
                        visited[nrow][ncol] = 1;
                        q.push({{nrow, ncol}, {r, c}});
                    } else {
                        if (nrow != parentR || ncol != parentC) return true;
                    }
                } 
            }
        }

        return false;
    }
};