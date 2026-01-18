class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Idea: use 2 pointers left and right to traverse the string. These form our window extremes.
        // Maintain a hashmap to keep a track of what elements we have seen so far in the window and at what idx.
        
        int n = s.size();
        if (n==0 || n==1) return n;
        int left = 0;
        int right = 0;
        unordered_map <char, int> charMap; // stores char -> index
        int maxLen = 0;
        while (left <n && right <n) {
            if (charMap.find(s[right]) == charMap.end()) {
                charMap[s[right]] = right;
            } else if (charMap.find(s[right]) != charMap.end()) {
                // First check if the character is at an index that is behind left
                if (charMap[s[right]] < left) {

                } else {
                    left = max(left, charMap[s[right]] + 1);
                }
                charMap[s[right]] = right;
            }
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;
    }
};