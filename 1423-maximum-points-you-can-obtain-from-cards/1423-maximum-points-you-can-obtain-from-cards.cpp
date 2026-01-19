class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int maxSum = 0;
        int currSum = 0;
        for(int i=0; i<k; i++) {
            currSum += cardPoints[i];
        }
        if (k == n) {
            return currSum;
        }

        int shift = k;
        int left = k-1;
        int right = n-1;
        while (shift >= 1) {
            currSum -= cardPoints[left];
            left--;
            currSum += cardPoints[right];
            right--;
            maxSum = max(currSum, maxSum);
            shift--;
        }
        return maxSum;
    }
};