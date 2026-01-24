class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> list;
        int openUsed = 0;
        int closedUsed = 0;
        string curr = "";
        generateNextCombination(list, curr, openUsed, closedUsed, n);
        return list;
    }

    void generateNextCombination(vector<string>& list, string& curr, int openUsed, int closedUsed, int n) {
        if (openUsed + closedUsed == 2*n) {
            list.push_back(curr);
            return;
        }

        if (openUsed < n) {
            curr.push_back('(');
            generateNextCombination(list, curr, openUsed+1, closedUsed, n);
            curr.pop_back();
        }
       
        if (closedUsed < openUsed) {
            curr.push_back(')');
            generateNextCombination(list, curr, openUsed, closedUsed+1, n);
            curr.pop_back();
        }

    }
};