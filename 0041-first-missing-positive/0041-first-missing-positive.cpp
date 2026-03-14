class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // Answer must lie within 1 and n+1

        // Pass 1: normalize all elements to n+1 if they are <= 0 and > n
        for (int i=0; i<n; i++) {
            if (nums[i] <= 0 || nums[i] > n) {
                nums[i] = n+1;
            }
        }

        // Pass 2: mark corresponding index as negative to show pressence
        for (int i=0; i<n; i++) {
            int num = abs(nums[i]);
            if (num > 0 && num <= n) {
                int index = num-1;
                if (nums[index] < 0) continue; 
                nums[index] = -nums[index];
            }
        }

        // Pass 3: go through array to find first non-negative index
        int ans = n+1;
        for (int i=0; i<n; i++) {
            if (nums[i] > 0) {
                ans = i+1;
                break;
            }
        }

        return ans;
    }
};