class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        formPartitions(ans, s, curr, 0);
        return ans;
    }

    void formPartitions(vector<vector<string>>& ans, string s, vector<string> curr, int currIndex) {
        if (currIndex == s.size()) {
            ans.push_back(curr);
            return;
        }


        for (int i=currIndex; i<s.size(); i++) {
            // i decides the interval of partitions
            string currPartition = s.substr(currIndex, i-currIndex+1);

            if (!isPalindrome(currPartition)) {
                continue;
            }

            curr.push_back(currPartition);
            formPartitions(ans, s, curr, i+1);
            curr.pop_back();
        }
    }

    bool isPalindrome(string& st) {
        if(st.size() == 1) {
            return true;
        }

        int n = st.size();
        for (int i=0; i<n; i++) {
            if (st[i] != st[n-i-1]) {
                return false;
            }
        }

        return true;
    }
};