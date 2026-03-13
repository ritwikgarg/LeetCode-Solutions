class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        string ans = "";
        int n = s.size();

        vector<vector<char>> matrix(numRows);
        int row = 0;
        bool down = true;

        for (int i = 0; i < n; i++) {
            if (row >= numRows && down == true) {
                row -= 2;
                down = false;
            }
            else if (row < 0 && down == false) {
                row += 2;
                down = true;
            }

            matrix[row].push_back(s[i]);

            if (row < numRows && down == true) {
                row++;
            } 
            else if (row >= 0 && down == false) {
                row--;
            }
        }

        for (int i = 0; i < numRows; i++) {
            int len = matrix[i].size();
            for (int j = 0; j < len; j++) {
                ans += matrix[i][j];
            }
        }

        return ans;
    }
};