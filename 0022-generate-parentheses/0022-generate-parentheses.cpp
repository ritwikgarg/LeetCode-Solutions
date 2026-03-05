class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr = "";
        generate(n, 0, 0, curr, ans);
        return ans;
    }

    void generate(int n, int openingCnt, int closingCnt, string curr, vector<string>& ans) {
        if (openingCnt == n && closingCnt == n) {
            ans.push_back(curr);
            return;
        }

        if (openingCnt < n) {
            generate(n, openingCnt+1, closingCnt, curr + "(", ans);
        }

        if (closingCnt < n && closingCnt < openingCnt) {
            generate(n, openingCnt, closingCnt+1, curr + ")", ans);
        }
    }
};