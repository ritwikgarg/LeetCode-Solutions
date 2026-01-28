class Solution {
public:
    string removeKdigits(string num, int k) {
        // Idea: remove the first k largest elements we encounter from left -> right
    
        stack<char> st;
        int n = num.size();

        if (k>n) {
            return "0";
        }

        for (int i=0; i<n; i++) {
            char digit = num[i];

            while(!st.empty() && st.top() > digit && k>0) {
                st.pop();
                k--;
                if (k == 0) {
                    break;
                }
            }

            st.push(digit);
        }

        while (k>0) {
            st.pop();
            k--;
        }

        if (st.empty()) {
            return "0";
        }

        string ans = "";
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        int firstDigitIdx = ans.size();
        for (int i=0; i<ans.size(); i++) {
            if (ans[i] != '0') {
                firstDigitIdx = i;
                break;
            }
        }

        if (firstDigitIdx == ans.size()) {
            return "0";
        }

        return ans.substr(firstDigitIdx, ans.size()-firstDigitIdx+1);
    }
};