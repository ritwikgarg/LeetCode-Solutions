class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map <char, vector<char>> letterMap = {
            {'2', {'a', 'b', 'c'}}, {'3', {'d', 'e', 'f'}},
            {'4', {'g', 'h', 'i'}}, {'5', {'j', 'k', 'l'}}, {'6', {'m', 'n', 'o'}},
            {'7', {'p', 'q', 'r', 's'}}, {'8', {'t', 'u', 'v'}}, {'9', {'w', 'x', 'y', 'z'}}
        };

        vector<string> combinations;
        string curr = "";
        makeCombinations(combinations, letterMap, digits, digits.size(), curr, 0);
        return combinations;
    }

    void makeCombinations(vector<string>& combinations, unordered_map<char, vector<char>>& letterMap, string& digits, int digitCount, string& curr, int currDigitIndex) {
        if (curr.size() == digitCount) {
            combinations.push_back(curr);
            return;
        }

        char currDigit = digits[currDigitIndex];
        for (int i=0; i<letterMap[currDigit].size(); i++) {
            curr.push_back(letterMap[currDigit][i]);
            makeCombinations(combinations, letterMap, digits, digitCount, curr, currDigitIndex+1);
            curr.pop_back();
            makeCombinations(combinations, letterMap, digits, digitCount, curr, currDigitIndex+1);
        }

    }
};