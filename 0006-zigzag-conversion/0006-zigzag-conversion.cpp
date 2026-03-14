class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        int n = s.size();
        vector<string> matrix(numRows);

        int row = 0;
        int direction=1;

        for (int i=0; i<n; i++) {
            matrix[row] += s[i];

            if (row == numRows-1) {
                direction = -1;
            } 
            if (row == 0) {
                direction = 1;
            }

            row += direction;
            
        }

        string ans = "";
        for (int i=0; i<numRows; i++) {
            ans+=matrix[i];
        }

        return ans;
    }
};