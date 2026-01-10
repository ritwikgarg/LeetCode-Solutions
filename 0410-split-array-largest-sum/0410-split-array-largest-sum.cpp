class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        // Idea: subarray sum is monotonically increasing across the array
        // We do BS on this. For a given maxSum, we try to see how many subarrays we can form, with max sum of each subArray not exceeding maxSum
        // If no. of subarrays > k, make maxSum larger so that more elements can fit within a single subarray without violating the maxSum condition and we can fit no. of subarrays within k
        // If no. of subarrays <= k, means that we  made maxSum so large that we can make < k no. of subarrays with each subarray sum not exceeding maxSum. These subarrays can easily be broken down to make more than k subarrays. Hence we should try to make maxSum smaller.

        int n = nums.size();
        int low = maxElement(nums);
        int high = sumElems(nums);

        while (low <= high) {
            int mid = low + (high-low)/2;
            if(countHowManySubarraysPossibleWithAllowedMaxSum(nums, n, mid) > k) {
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        return low;
    }

    int countHowManySubarraysPossibleWithAllowedMaxSum(vector<int>& nums, int n, int maxSumAllowed) {
        int noOfSubarraysPossible = 1;
        int subarraySum = 0;
        int i=0;
        while (i<n) {
            subarraySum += nums[i];
            if (subarraySum <= maxSumAllowed) {
                i++;
            } else {
                noOfSubarraysPossible++;
                subarraySum = nums[i];
                i++;
            }
        }
        return noOfSubarraysPossible;
    }

    int maxElement(vector<int>& nums) {
        int maxElem = INT_MIN;
        for (int i: nums) {
            maxElem = max(maxElem, i);
        }
        return maxElem;
    }

    int sumElems(vector<int>& nums) {
        int sum = 0;
        for (int i: nums) {
            sum += i;
        }
        return sum;
    }
};