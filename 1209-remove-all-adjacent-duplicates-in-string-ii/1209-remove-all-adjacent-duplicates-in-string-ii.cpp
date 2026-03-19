class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack <pair<char, int>> st;
        int n = s.size();

        for (int i=0; i<n; i++) {
            if (!st.empty() && st.top().first == s[i]) {
                st.top().second++;
                if (st.top().second >= k) {
                    st.pop();
                }
            } else {
                st.push({s[i], 1});
            }
        }

        string ans = "";
        while (!st.empty()) {
            pair<char, int> p = st.top();
            for (int i=1; i<=p.second; i++) {
                ans += p.first;
            }
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};