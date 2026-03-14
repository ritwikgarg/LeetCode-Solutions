    class Solution {
    public:
        string convert(string s, int numRows) {
            if (numRows == 1) {
                return s;
            }
            vector<string> ans(numRows);
            dfs(s, 0, 0, 1, numRows, ans);
            
            string answer = "";
            for (int i=0; i<numRows; i++) {
                answer += ans[i];
            }

            return answer;
        }

        void dfs(string& s, int index, int currRow, int direction, int numRows, vector<string>& ans) {
            if (index == s.size()) {
                return;
            }

            ans[currRow] += s[index];

            if (currRow == numRows-1) {
                direction = -1;
            }
            if (currRow == 0) {
                direction = 1;
            }

            currRow += direction;

            dfs(s, index+1, currRow, direction, numRows, ans);
        }
    };