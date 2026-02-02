class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        string currExp = "";
        solve(ans, num, target, currExp, 0, 0, 0);
        return ans;
    }

    void solve(vector<string>& ans, string& num, int target, string& currExp, long long currValue, int currIdx, long long prevOperand) {
        if (currIdx == num.size()) {
            if (currValue == target) {
                ans.push_back(currExp);
            }
            return;
        }

        for (int i=currIdx; i<num.size(); i++) {

            string str = num.substr(currIdx, i-currIdx+1);
            if (i > currIdx && num[currIdx] == '0') break;
            long value = stoll(str);

            if (currExp == "") {
                solve(ans, num, target, str, value, i+1, value);
                continue;
            }

            string updatedString = currExp+"+"+str;
            solve(ans, num, target, updatedString, currValue+value, i+1, value);

            updatedString = currExp+"-"+str;
            solve(ans, num, target, updatedString, currValue-value, i+1, -value);

            updatedString = currExp+"*"+str;
            solve(ans, num, target, updatedString, (value*prevOperand) + (currValue-prevOperand), i+1, value*prevOperand); 
        }
    }

};