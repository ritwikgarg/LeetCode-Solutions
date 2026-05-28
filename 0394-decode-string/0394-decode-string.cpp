class Solution {
public:
    string decodeString(string s) {
        stack<char> st;

        for (char ch : s) {
            if (ch != ']') {
                st.push(ch);
            } else {
                string inside = "";

                while (!st.empty() && st.top() != '[') {
                    inside += st.top();
                    st.pop();
                }

                reverse(inside.begin(), inside.end());

                // pop '['
                st.pop();

                string numStr = "";
                while (!st.empty() && isdigit(st.top())) {
                    numStr += st.top();
                    st.pop();
                }

                reverse(numStr.begin(), numStr.end());

                int multiplier = stoi(numStr);

                string expanded = "";
                for (int i = 0; i < multiplier; i++) {
                    expanded += inside;
                }

                for (char c : expanded) {
                    st.push(c);
                }
            }
        }

        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());

        return result;
    }
};