class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited (n,0);

        int count = 0;
        for (int i=0; i<n; i++) {
            if (visited[i] == 0) {
                count++;
                queue<int> q;
                q.push(i);

                while (!q.empty()) {
                    int currNode = q.front();
                    q.pop();
                    visited[currNode] = 1;

                    for (int i=0; i<n; i++) {
                        if (isConnected[currNode][i] == 1) {
                            if (!visited[i])
                                q.push(i);
                        }
                    }
                }
            }
        }
        return count;
    }
};