class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adjList(numCourses);

        for(auto &edge:prerequisites) {
            int u = edge[0];
            int v = edge[1];
            adjList[v].push_back(u);
        }

        vector<int> topoSort;
        vector<int> indegree(numCourses, 0);

        for (int i=0; i<numCourses; i++) {
            for (auto it:adjList[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;
        for (int i=0; i<numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            topoSort.push_back(node);

            for (int neighbor:adjList[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) q.push(neighbor);
            }
        }

        return (topoSort.size() == numCourses) ? topoSort : vector<int>{};
    }
};