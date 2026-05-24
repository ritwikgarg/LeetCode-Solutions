class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<vector<int>> distance(n, vector<int>(m, 0));

        queue<pair<pair<int, int>, int>> q; //Stores {{row,col}, dist}

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (mat[i][j] == 0) {
                    q.push({{i,j}, 0});
                    visited[i][j] = 1;
                    distance[i][j] = 0;
                }
            }
        }

        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, -1, 0, 1};
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int dist = q.front().second;
            q.pop();

            for (int i=0; i<4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if (nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol]) {
                    q.push({{nrow, ncol}, dist+1});
                    visited[nrow][ncol] = 1;
                    distance[nrow][ncol] = dist+1;
                }
            }
        }

        return distance;
    }
};