class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map <char, int> freqMap;
        int m = s.size();
        int n = t.size();

        int req = 0;
        for (int i=0; i<n; i++) {
            freqMap[t[i]]++; // Initialize a map which contains the counts of char required in s that are in t
            req++;
        }

        int left = 0, leftIdx = -1;
        int right = 0;
        int have = 0; // Keeps a track of how many chars in curr substring in s contains chars that are in t
        int minLen = INT_MAX;

        while (right < m) {
            char ch = s[right];
            freqMap[ch]--;
            if (freqMap[ch] >= 0) {
                have++;
            }

            while (have >= req) {
                int len = right-left+1;
                if (minLen >= len) {
                    minLen = len;
                    leftIdx = left; 
                }
                freqMap[s[left]]++;
                if (freqMap[s[left]] > 0) {
                    have--;
                }
                left++;
            }
            right++;
        }

        if (leftIdx == -1) return "";

        return s.substr(leftIdx, minLen);
    }
};