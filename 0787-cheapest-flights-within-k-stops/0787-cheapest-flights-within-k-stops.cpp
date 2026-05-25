class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adjList(n);

        for (auto &edge: flights) {
            int from = edge[0];
            int to = edge[1];
            int price = edge[2];
            adjList[from].push_back({to, price});
        }

        vector<vector<int>> price(k + 2, vector<int>(n, INT_MAX));

        set<pair<int, pair<int, int>>> st; // stores {price, {flightsTaken, dest}} node
        st.insert({0, {0, src}});

        while (!st.empty()) {
            auto it = *(st.begin());
            int currNode = it.second.second;
            int currPrice = it.first;
            int flightsTaken = it.second.first;
            st.erase(it);

            if (currNode == dst) {
                return currPrice;
            }

            if (flightsTaken == k + 1) {
                continue;
            }

            for (auto it:adjList[currNode]) {
                int nextNode = it.first;
                int flightCost = it.second;

                int newFlightsTaken = flightsTaken + 1;
                int newPrice = currPrice + flightCost;

                if (newPrice < price[newFlightsTaken][nextNode]) {
                    price[newFlightsTaken][nextNode] = newPrice;
                    st.insert({newPrice, {newFlightsTaken, nextNode}});
                }
            }
        }

        return -1;
    }
};