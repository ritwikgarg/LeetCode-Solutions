class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        vector<int> leftNeighbor (n);
        vector<int> rightNeighbor (n);

        leftNeighbor[0] = 1;
        rightNeighbor[n-1] = 1;

        for(int i=1; i<n; i++) {
            if (ratings[i-1] < ratings[i]) {
                leftNeighbor[i] = leftNeighbor[i-1] + 1;
            } else {
                leftNeighbor[i] = 1;
            }
        }

        for(int i=n-2; i>=0; i--) {
            if (ratings[i] > ratings[i+1]) {
                rightNeighbor[i] = rightNeighbor[i+1] + 1;
            } else {
                rightNeighbor[i] = 1;
            }
        }

        int minCandies = 0;
        
        for (int i=0; i<n; i++) {
            minCandies += max(leftNeighbor[i], rightNeighbor[i]);
        }

        return minCandies;
    }
};