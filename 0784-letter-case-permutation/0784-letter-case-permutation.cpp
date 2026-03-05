class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        string curr = "";
        generatePermutations(s, 0, curr, ans);
        return ans;    
    }

    void generatePermutations(string s, int currIndex, string curr, vector<string>& ans) {

        if (currIndex == s.size()) {
            ans.push_back(curr);
            return;
        }

        char ch = s[currIndex];
        if(isalpha(s[currIndex])) {
            generatePermutations(s, currIndex+1, curr+ch, ans);
            if (isupper(ch)) {
                ch = tolower(ch);
                generatePermutations(s, currIndex+1, curr+ch, ans);
            } else {
                ch = toupper(ch);
                generatePermutations(s, currIndex+1, curr+ch, ans);
            }
        } else {
            generatePermutations(s, currIndex+1, curr+s[currIndex], ans);
        }
    }


};