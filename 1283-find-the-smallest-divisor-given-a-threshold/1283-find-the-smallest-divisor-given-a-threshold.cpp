class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        // Idea: use binary search over possible divisors
        // Low = 1, High = maxElement

        int n = nums.size();
        if (threshold < n) return -1;

        int low = 1;
        int high = maxElement(nums);
        int ans = 0;

        while (low <= high) {
            int mid = low + (high-low)/2;
            if (divisorSum(nums, mid) <= threshold) {
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }

        return ans;
    }

    int divisorSum(vector<int>& nums, int divisor) {
        int sum = 0;
        for (int i=0; i<nums.size(); i++) {
            sum = sum + ceil((double)nums[i]/(double)divisor);
        }
        return sum;
    }

    int maxElement(vector<int>& nums) {
        int maxElem = INT_MIN;
        for (int i: nums) {
            maxElem = max(i, maxElem);
        }
        return maxElem;
    }
};