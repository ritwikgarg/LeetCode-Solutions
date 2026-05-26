class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        multiset<int> cookieSize(s.begin(), s.end());
        int n = g.size();

        int count = 0;
        for (int i=0; i<n; i++) {
            if (cookieSize.size() == 0) return count;
            auto it = cookieSize.lower_bound(g[i]);

            if (it != cookieSize.end()) {
                count++;
                cookieSize.erase(it);
            }   
        }
        return count;
    }
};