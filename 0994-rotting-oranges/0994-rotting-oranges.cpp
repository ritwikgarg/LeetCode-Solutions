class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(); //rows
        int m = grid[0].size(); //cols

        queue<pair<pair<int, int>, int>> q; // Stores ((row, col), time)
        vector<vector<int>> visited(n, vector<int>(m, 0));

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i,j},0});
                    visited[i][j] = 2;
                } else {
                    visited[i][j] = 0; 
                }
            }
        }

        int time = 0;
        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, 1, 0, -1};
        while (!q.empty()) {
            pair<pair<int, int>, int> currNode = q.front();
            q.pop();

            time = max(time, currNode.second);
            int currRow = currNode.first.first;
            int currCol = currNode.first.second;

            for (int i=0; i<4; i++) {
                int nrow = currRow + dRow[i];
                int ncol = currCol + dCol[i];

                if (nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]!=2 && grid[nrow][ncol] == 1) {
                    q.push({{nrow, ncol}, time+1});
                    visited[nrow][ncol] = 2;
                }
            }
        }

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (visited[i][j] != 2 && grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return time;

    }
};