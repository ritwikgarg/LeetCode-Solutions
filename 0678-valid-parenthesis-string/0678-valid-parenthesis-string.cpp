class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        int min = 0;
        int max = 0;

        for (int i=0; i<n; i++) {
            char ch = s[i];
            if (ch == '(') {
                min++;
                max++;
            } else if (ch == ')') {
                max--;
                min--;
            } else if (ch == '*') {
                min--;
                max++;
            }

            if (min < 0) min = 0;
            if (max < 0) return false;
        }

        return (min == 0) ? true : false;
    }
};