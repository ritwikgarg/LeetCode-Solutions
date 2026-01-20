class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map <char, int> need; // freq map of chars in t
        unordered_map <char, int> have; // freq map of chars in s

        int m = s.size();
        int n = t.size();

        for (int i=0; i<n; i++) {
            need[t[i]]++;
        }

        int left = 0;
        int right = 0;
        int required = need.size(); // no. of distinct characters in need;
        int formed = 0; // no. ofs characters we have gathered in s, that are needed in t.

        int leftIdx = -1;
        int rightIdx = -1;
        int minLen = INT_MAX;
        while (right < m) {
            char ch = s[right];
            have[ch]++;
            if (need.find(ch)!=need.end() && have[ch] == need[ch]) {
                formed++;
            }
            while (formed >= required) {
                if ((right-left+1) <= minLen) {
                    minLen = right-left+1;
                    rightIdx = right;
                    leftIdx = left;
                }
                have[s[left]]--;
                if (need.find(s[left]) != need.end() && have[s[left]] < need[s[left]]) {
                    formed--;
                }
                left++;
            }
            right++;
        }

        if (leftIdx == -1) {
            return "";
        }
        return s.substr(leftIdx, minLen);

    }
};