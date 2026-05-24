class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        if (n==0) return 0;

        int count = 0;
        vector<int> visited(n,0);

        while(true) {
            int currNode = findNextUnvisited(visited);
            count++;
            DFS(currNode, isConnected, visited);
            if (allNodesVisited(visited)) return count;
        }
        return count;
    }

    void DFS(int node, vector<vector<int>>& adjMatrix, vector<int>& visited) {
        visited[node] = 1; // Mark curr node as visited
        vector<int> neighbors = findNeighbors(node, adjMatrix);

        for (int it: neighbors) {
            if (!visited[it]) {
                DFS(it, adjMatrix, visited);
            }
        }
    }

    bool allNodesVisited(vector<int>& visited) {
        for (int it: visited) {
            if (it == 0) return false;
        }
        return true;
    }

    int findNextUnvisited(const vector<int>& visited) {
        for (int i = 0; i < visited.size(); i++) {
            if (visited[i] == 0) return i;
        }
        return -1;
    }

    vector<int> findNeighbors(int node, vector<vector<int>>& adjMatrix) {
        vector<int> neighbors;
        int n = adjMatrix.size();

        for (int i=0; i<n; i++) {
            if (adjMatrix[node][i] == 1) neighbors.push_back(i);
        }

        return neighbors;
    }
};