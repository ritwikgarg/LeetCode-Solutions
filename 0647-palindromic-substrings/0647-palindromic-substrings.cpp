class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        int len = s.size();

        for (int i=0; i<len; i++) {
            int oddPalindromes = expand(i, i, s);
            int evenPalindromes = expand(i, i+1, s);

            res += oddPalindromes;
            res += evenPalindromes;
        }
        return res;
    }

    // Returns no. of substrings that can be formed by starting from left and right indices
    int expand(int left, int right, string& s) {
        int len = s.size();

        int count = 0;
        while(left >=0 && right < len) {
            if (s[left] == s[right]) {
                count++;
                left--;
                right++;
            } else {
                break;
            }
        }

        return count;
    }
};