class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());

        int maxLen = 0;
        for (auto &w : wordDict) maxLen = max(maxLen, (int)w.size());

        // memo[i] = -1 unknown, 0 false, 1 true for "can break s starting at i"
        vector<int> memo(s.size() + 1, -1);

        return partitionWord(s, st, 0, memo, maxLen);
    }

private:
    bool partitionWord(string& s,
                       unordered_set<string>& st,
                       int start,
                       vector<int>& memo,
                       int maxLen) {
        if (start == (int)s.size()) return true;

        if (memo[start] != -1) return memo[start] == 1;

        int n = s.size();
        int endLimit = min(n, start + maxLen);

        for (int end = start; end < endLimit; end++) {
            // substring s[start..end]
            if (st.find(s.substr(start, end - start + 1)) != st.end()) {
                if (partitionWord(s, st, end + 1, memo, maxLen)) {
                    memo[start] = 1;
                    return true;
                }
            }
        }

        memo[start] = 0;
        return false;
    }
};