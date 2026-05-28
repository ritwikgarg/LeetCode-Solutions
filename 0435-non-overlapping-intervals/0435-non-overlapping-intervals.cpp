class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 1) return 0;

        sort(intervals.begin(), intervals.end());

        int i=0;
        int j=1;
        int count = 0;

        while (i<n && j<n) {

            int currentStart = intervals[i][0];
            int currentEnd = intervals[i][1];

            int nextStart = intervals[j][0];
            int nextEnd = intervals[j][1];

            // No overlap
            if (currentEnd <= nextStart) {
                i=j;
                j++;
            }

            // Overlap;
            else if (currentEnd <= nextEnd) {
                count++;
                j++;
            }

            else if (currentEnd > nextEnd) {
                i = j;
                j++;
                count++;
            }
        }
        return count;
    }
};