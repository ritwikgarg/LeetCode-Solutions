class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        vector<int> count(n);
        int i=0; // write pointer

        for (int j=0; j<n; j++) {
            s[i] = s[j];

            if (i > 0 && s[i] == s[i-1]) {
                count[i] = count[i-1] + 1;
            } else {
                count[i] = 1;
            }

            if (count[i] == k) {
                i-=k;
            }
            i++;
        }

        return s.substr(0, i);
    }
};