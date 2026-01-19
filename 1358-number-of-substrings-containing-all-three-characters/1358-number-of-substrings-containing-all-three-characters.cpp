class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map <char, int> charMap; // stores char -> last seen index
        int n = s.size();
        int count = 0;
        for (int i=0; i<n; i++) {
            char ch = s[i];
            charMap[ch] = i;
            if (charMap.size() == 3) {
                count += (min(charMap['c'], min(charMap['a'], charMap['b'])) + 1);
            }
        }
        return count;
    }
};