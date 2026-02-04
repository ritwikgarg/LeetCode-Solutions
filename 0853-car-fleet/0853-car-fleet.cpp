class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> positionTimePair;
        int n = position.size();

        for (int i=0; i<n; i++) {
            double time = (double)(target - position[i])/(double)speed[i];
            positionTimePair.push_back({position[i], time});
        }

        sort(positionTimePair.begin(), positionTimePair.end(), greater<>());

        int fleets = 0;
        double slowestTime = -1.0;
        for (int i=0; i<n; i++) {
            int time = positionTimePair[i].second; 
            if (time > slowestTime) {
                fleets++;
                slowestTime = time;
            }
        }

        return fleets;
    }
};