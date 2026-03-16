class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxLen = INT_MIN;
        int startingIndex = 0;

        for (int i=0; i<n; i++) {
            int oddLen = expand(s, i, i);
            int evenLen = expand(s, i, i+1);

            int len = max(oddLen, evenLen);

            if (len > maxLen) {
                maxLen = len;
                startingIndex = i - (len - 1) / 2;
            }
        }

        return s.substr(startingIndex, maxLen);
    }

    int expand(string &s, int i, int j) {
        int maxLen = 0;
        while (i>=0 && j<s.size() && s[i] == s[j]) {
            maxLen = j-i+1;
            i--;
            j++;
        }

        return maxLen;
    }
};