class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> leftMax (n, 0); // stores height of first tallest building to the left of current building
        vector<int> rightMax (n, 0); // stores height of first tallest building to the right of current building

        int rightMaxTillNow = height[n-1];
        for (int i=n-1; i>=0; i--) {
            rightMaxTillNow = max(rightMaxTillNow, height[i]);
            rightMax[i] = rightMaxTillNow;
        }

        int leftMaxTillNow = height[0];
        for (int i=0; i<n; i++) {
            leftMaxTillNow = max(leftMaxTillNow, height[i]);
            leftMax[i] = leftMaxTillNow;
        }

        int water = 0;
        for (int i=0; i<n; i++) {
            water += min(leftMax[i], rightMax[i]) - height[i];
        }

        return water
        ;
    }
};