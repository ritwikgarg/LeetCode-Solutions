class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        int i = 0; // write pointer
        int j = 0; // read pointer

        while (j < n) {
            
            if (i > 0 && s[i-1] == s[j]) {
                i--;
                i = max(0, i);
                j++;
                continue;
            }

            s[i++] = s[j++];
        }

        return s.substr(0, i);
    }
};