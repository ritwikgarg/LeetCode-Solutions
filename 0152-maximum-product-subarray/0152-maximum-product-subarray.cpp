class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int maxProd = nums[0];
        int currMax = 1;
        int currMin = 1;
        for (int i=0; i<n; i++) {
            if (nums[i] == 0) {
                currMax = 1;
                currMin = 1;
            } 

            int temp = currMax;
            currMax = max(max(currMax * nums[i], currMin * nums[i]), nums[i]); 
            currMin = min(min(temp * nums[i], currMin * nums[i]), nums[i]);
            maxProd = max(max(currMax, currMin), maxProd);
        }
        return maxProd;
    }
};