class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        int len = s.length();
        int i=0;
        while (i<len) {
            char ch = s[i];

            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
                i++;
            }

            if (ch == ')' || ch == '}' || ch == ']') {
                char last = st.top();
                st.pop();
                if (last == '(' && ch == ')' || last == '{' && ch == '}' || last == '[' && ch == ']') {
                    i++;
                    continue;
                }
                 else {
                    return false;
                 }
            }
        }
        if (st.empty() != true) {
            return false;
        }

        return true;
    }
};