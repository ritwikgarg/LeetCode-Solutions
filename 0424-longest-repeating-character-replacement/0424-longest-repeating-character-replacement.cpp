class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int left = 0;
        int right = 0;
        int maxLen = 0;
        unordered_map <char, int> freqMap;
        int maxFreq = 1;

        while (right < n) {
            char ch = s[right];
            if (freqMap.find(ch) == freqMap.end()) {
                freqMap[ch] = 1;
            } else {
                freqMap[ch]++;
                if (freqMap[ch] > maxFreq) {
                    maxFreq = freqMap[ch];
                }
            }
            int conversionsReq = (right-left+1) - maxFreq;
            if (conversionsReq > k) {
                freqMap[s[left]]--;
                // Update maxFreq
                for (auto it: freqMap) {
                    maxFreq = max(maxFreq, it.second);
                }
                left++;
            }
            maxLen = max(maxLen, right-left+1);
            right++;
        }
        return maxLen;
    }
};