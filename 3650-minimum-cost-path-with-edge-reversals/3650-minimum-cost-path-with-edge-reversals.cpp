class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adjList(n);

        for (auto &edge: edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adjList[u].push_back({v, w});
            adjList[v].push_back({u, 2*w});
        }

        vector<int> distance(n, INT_MAX);
        set<pair<int, int>> st; // stores {distance, node}
        st.insert({0, 0});
        distance[0] = 0;

        while (!st.empty()) {
            auto it = *(st.begin());
            int currNode = it.second;
            int currDist = it.first;
            st.erase(it);

            if (currNode == n-1) return currDist;

            for (auto &neighbor:adjList[currNode]) {
                int nextNode = neighbor.first;
                int nextDist = neighbor.second;

                int newDist = currDist + nextDist;

                if(newDist < distance[nextNode]) {
                    if (distance[nextNode] != INT_MAX) st.erase({distance[nextNode], nextNode});
                    distance[nextNode] = newDist;
                    st.insert({newDist, nextNode});
                }
            }
        }
        return -1;
    }
};