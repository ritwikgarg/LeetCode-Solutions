class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);

        // Build adjList
        for (auto &edge:prerequisites) {
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
        }

        vector<int> indegree(numCourses, 0);

        // Build indegree
        for (int i=0; i<numCourses; i++) {
            for (auto &it : adjList[i]) {
                indegree[it]++;
            }
        }

        int count = 0;

        queue<int> q;
        for (int i=0; i<numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for (int neighbor: adjList[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        if (count == numCourses) return true;
        return false;
    }
};