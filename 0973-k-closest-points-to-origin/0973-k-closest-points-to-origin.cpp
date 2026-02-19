struct Point {
    double distance;
    vector<int> coordinates;

    Point(): distance (0.0) {}

    Point(double distance, int x, int y) {
        this->distance = distance;
        coordinates.push_back(x);
        coordinates.push_back(y);
    }
};

class compare {
public:
    bool operator()(Point* a, Point* b) {
        return a->distance > b->distance;
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<Point*, vector<Point*>, compare> minHeap;
        
        int n = points.size();
        
        for (int i=0; i<n; i++) {
            double dist = calculateDistanceToOrigin(points[i][0], points[i][1]);
            minHeap.push(new Point(dist, points[i][0], points[i][1]));
        }

        vector<vector<int>> ans;
        for (int i=0; i<k; i++) {
            Point* pt = minHeap.top();
            ans.push_back({pt->coordinates[0], pt->coordinates[1]});

            minHeap.pop();
        }

        return ans;
    }

    double calculateDistanceToOrigin(int x, int y) {
        return (double)x*x + (double)y*y;
    }
};