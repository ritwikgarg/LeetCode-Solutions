class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        return minHP(0, 0, m, n, dungeon, dp);
    }

    int minHP(int row, int col, int m, int n, vector<vector<int>>& dungeon, vector<vector<int>>& dp) {
        if (row <0 || row>=m || col <0 || col>=n) return INT_MAX;

        if (dp[row][col] != -1) return dp[row][col];

        if (row == m-1 && col == n-1) {    
            if (dungeon[row][col] < 0) {
                return abs(dungeon[row][col]) + 1;
            }
            else {
                return 1;
            }
        }

        int bottomHP = minHP(row+1, col, m, n, dungeon, dp);
        int rightHP = minHP(row, col+1, m, n, dungeon, dp);

        int result = min(bottomHP, rightHP) - dungeon[row][col];

        return dp[row][col] = (result > 0) ? result : 1;
    }
};