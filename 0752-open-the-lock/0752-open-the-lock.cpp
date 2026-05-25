class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if (target == "0000") return 0;
        unordered_set<string> st(deadends.begin(), deadends.end());
        if (st.count(target)) return -1;
        if (st.count("0000")) return -1;

        // Idea is to start with "0000" as the source node
        // Build its neighbors on the fly by changing each digit and checking its not in deadends

        unordered_set<string> visited;
        queue<pair<string, int>> q; // Stores (code, turns)
        q.push({"0000", 0});

        while (!q.empty()) {
            string currCode = q.front().first;
            int currSteps = q.front().second;
            q.pop();

            if (currCode == target) return currSteps;

            vector<string> neighbors;
            vector<int> diff = {-1, 1};
            string copy = currCode;
            for (int i=0; i<4; i++) {
                int currNo = copy[i] - '0';
                for (int j=0; j<2; j++) {
                    int newNo = (currNo + diff[j] + 10) % 10;
                    copy[i] = char(newNo + '0');
                    if (!st.count(copy)) {
                        neighbors.push_back(copy);
                    }
                }
                copy = currCode;
            }

            for (string &ne:neighbors) {
                if (!st.count(ne) && !visited.count(ne)) {
                    visited.insert(ne);
                    q.push({ne, currSteps+1});
                }
            }
        }
        return -1;
    }
};