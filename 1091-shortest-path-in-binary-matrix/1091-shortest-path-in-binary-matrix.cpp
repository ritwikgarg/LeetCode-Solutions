class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        if (n==1) return 1;

        vector<vector<int>> distance(n, vector<int>(n, INT_MAX));
        distance[0][0] = 1;

        queue<pair<pair<int, int>, int>> q; // Stores {{row, col}, dist}
        q.push({{0,0}, 1});
        int minDist = INT_MAX;

        vector<int> drow = {-1, 0, 1, 0, -1, 1, -1, 1};
        vector<int> dcol = {0, -1, 0, 1, 1, -1, -1, 1};
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int dist = q.front().second;
            q.pop();

            for (int i=0; i<8; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if (nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==0) {
                    if (dist + 1 < distance[nrow][ncol]) {
                        distance[nrow][ncol] = dist + 1;
                        q.push({{nrow, ncol}, dist + 1});
                    }
                }
            }
        } 
        if (distance[n-1][n-1] == INT_MAX) return -1;
        return distance[n-1][n-1];
    }
};