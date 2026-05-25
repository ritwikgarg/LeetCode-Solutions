class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adjList(n);

        for (auto &edge: times) {
            int u = edge[0] - 1;
            int v = edge[1] - 1;
            int w = edge[2];
            adjList[u].push_back({v,w});
        }

        vector<int> minTime(n, INT_MAX);
        minTime[k-1] = 0;

        set<pair<int, int>> st; //stores {time, node}
        st.insert({0, k-1});

        while (!st.empty()) {
            auto it = *(st.begin());
            int currTime = it.first;
            int currNode = it.second;
            st.erase(it);

            for (auto &neighbor:adjList[currNode]) {
                int nextNode = neighbor.first;
                int travelTime = neighbor.second;

                int newTime = currTime + travelTime;
                if (newTime < minTime[nextNode]) {
                    if (minTime[nextNode] != INT_MAX) st.erase({minTime[nextNode], nextNode});
                    minTime[nextNode] = newTime;
                    st.insert({newTime, nextNode});
                }
            }
        }

        int maxTime = 0;
        for (int i=0; i<n; i++) {
            if(minTime[i] == INT_MAX) return -1;
            maxTime = max(maxTime, minTime[i]);
        }

        return maxTime;
    }
};