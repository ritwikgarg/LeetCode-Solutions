class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int totalTime = 0;

        for (int i=0; i<n-1; i++) {
            totalTime += calcTimeBetween2Points(points[i], points[i+1]);
        }

        return totalTime;
    }

    int calcTimeBetween2Points(vector<int>& p1, vector<int>& p2) {
        int time = 0;
        int xDiff = abs(p1[0] - p2[0]);
        int yDiff = abs(p1[1] - p2[1]);

        while(xDiff >0 && yDiff >0) {
            time++;
            xDiff--;
            yDiff--;
        }

        while(xDiff > 0) {
            xDiff--;
            time++;
        }

        while(yDiff > 0) {
            yDiff--;
            time++;
        }

        return time;
    }
};