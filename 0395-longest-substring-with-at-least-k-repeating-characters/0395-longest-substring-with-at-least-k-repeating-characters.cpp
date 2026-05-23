class Solution {
public:
    int longestSubstring(string s, int k) {
        int len = s.size();
        if (len  == 0) return 0;

        unordered_map<char, int> freqMap;

        for (auto ch: s) {
            freqMap[ch]++;
        }

        for(auto mp: freqMap) {
            int count = mp.second;
            char ch = mp.first;

            if (count < k) {
                int best = 0;
                int start = 0;
                for (int i=0; i<=len; i++) {
                    if (i == len || s[i] == ch) {
                        string part = s.substr(start, i-start);
                        best = max(best, longestSubstring(part, k));
                        start = i+1;
                    }
                }
                return best;
            }
        }
        return len;
    }
};