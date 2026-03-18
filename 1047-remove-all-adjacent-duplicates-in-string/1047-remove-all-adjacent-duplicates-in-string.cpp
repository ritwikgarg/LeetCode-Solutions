class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        int n = s.size();

        for (int i=0; i<n; i++) {
            char ch = s[i];

            if (!st.empty()) {
                if (st.top() == ch) {
                    st.pop();
                    continue;
                }
            }

            st.push(ch);
        }

        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};