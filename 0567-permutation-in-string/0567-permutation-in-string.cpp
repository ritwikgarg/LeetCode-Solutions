class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int windowSize = s1.size();
        int n = s2.size();

        if (n < windowSize) {
            return false;
        }

        unordered_map <char, int> s1charFreqMap;

        for (int i=0; i<s1.size(); i++) {
            s1charFreqMap[s1[i]]++;
        }

        unordered_map <char, int> windowCharFreqMap;
        for (int i=0; i<windowSize; i++) {
            windowCharFreqMap[s2[i]]++;
        }

        int left = 0;
        int right = left + windowSize - 1;
        while (left <= n - windowSize) {
            if (s1charFreqMap == windowCharFreqMap) {
                return true;
            }

            windowCharFreqMap[s2[left]]--;
            if (windowCharFreqMap[s2[left]] == 0) {
                windowCharFreqMap.erase(s2[left]);
            }

            left++;
            right++;

            windowCharFreqMap[s2[right]]++;
        }

        return false;
    }
};