class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<int>> minEffort(rows, vector<int>(cols, INT_MAX));

        minEffort[0][0] = 0;

        set<pair<int, pair<int, int>>> st;
        st.insert({0, {0, 0}});

        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, -1, 0, 1};
        while (!st.empty()) {
            auto it = *(st.begin());
            int r = it.second.first;
            int c = it.second.second;
            int e = it.first;
            st.erase(it);

            for (int i=0; i<4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if (nrow>=0 && nrow<rows && ncol>=0 && ncol<cols) {
                    int effortDiff = abs(heights[r][c] - heights[nrow][ncol]);
                    int newEffort = max(e, effortDiff);
                    if (newEffort < minEffort[nrow][ncol]) {
                        minEffort[nrow][ncol] = newEffort;
                        st.insert({newEffort, {nrow, ncol}});
                    }
                }
            }
        }

        return minEffort[rows-1][cols-1];
    }
};