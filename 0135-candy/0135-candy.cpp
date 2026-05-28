class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        int candy = n; // each child gets 1 candy

        int i = 1;

        while (i < n) {
            // Flat slope
            if (ratings[i] == ratings[i - 1]) {
                i++;
                continue;
            }

            // Increasing slope
            int peak = 0;
            while (i < n && ratings[i] > ratings[i - 1]) {
                peak++;
                candy += peak;
                i++;
            }

            // Decreasing slope
            int dip = 0;
            while (i < n && ratings[i] < ratings[i - 1]) {
                dip++;
                candy += dip;
                i++;
            }

            // Peak was counted from both increasing and decreasing sides
            candy -= min(peak, dip);
        }

        return candy;
    }
};