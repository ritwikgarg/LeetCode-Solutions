class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> monotonicStack; // monotonic stack, largest digit on top, smallest at the bottom
        int n = num.size();

        if (k==n) {
            return "0";
        }

        for (int i=0; i<n; i++) {
            while (!monotonicStack.empty() && k>0 && monotonicStack.top() > num[i]) {
                monotonicStack.pop();
                k--;
                if (k==0) {
                    break;
                }
            }
            monotonicStack.push(num[i]);
        }

        while (k>0 && !monotonicStack.empty()) {
            monotonicStack.pop();
            k--;
        }

        string temp;
        while (!monotonicStack.empty()) {
            temp.push_back(monotonicStack.top());
            monotonicStack.pop();
        }

        reverse(temp.begin(), temp.end());

        string ans;
        bool found1stDigit = false;
        for (int i=0; i<temp.size(); i++) {
            if (temp[i] != '0') {
                found1stDigit = true;
            }

            if (found1stDigit) {
                ans.push_back(temp[i]);
            }
        }

        if (ans.empty()) {
            return "0";
        }
        
        return ans;

    }
};