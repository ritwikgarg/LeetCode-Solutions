class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        vector<string> words;

        for (int i=0; i<n; i++) {
            char ch = s[i];
            if (ch == ' ') {
                continue;
            } else {
                string temp = "";
                int j = i;
                while(ch != ' ') {
                    temp += ch;
                    j++;
                    if (j > n-1) {
                        break;
                    } else {
                        ch = s[j];
                    }
                }
                words.push_back(temp);
                i = j - 1;
            }
        }

        reverse(words.begin(), words.end());
        string ans = "";
        for (int i=0; i<words.size(); i++) {
            if (i == words.size() - 1) {
                ans += words[i];
                break;
            }
            ans += words[i] + ' ';
        }
        return ans;
    }
};