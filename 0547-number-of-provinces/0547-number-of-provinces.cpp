class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n, 0);

        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                DFS(i, isConnected, visited);
            }
        }

        return count;
    }

    void DFS(int node, vector<vector<int>>& isConnected, vector<int>& visited) {
        visited[node] = 1;

        int n = isConnected.size();

        for (int neighbor = 0; neighbor < n; neighbor++) {
            if (isConnected[node][neighbor] == 1 && !visited[neighbor]) {
                DFS(neighbor, isConnected, visited);
            }
        }
    }
};