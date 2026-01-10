class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        // Idea: Binary Search over search space of subarray sum
        // Subarray sum increases monotonically across the array

        // Low -> max element (lowest possible subarray sum if each element is its own subarray, k = n)
        // Max -> sum of all elements (lowest possible subarray sum if each element is in the same subarray, k =1)

        // If k=s subarrays can satifsy the maximumSum per subarray cap, then all k>=s && k<=n can also satisfy
        // the condition without violating maximumSum per subarray cap
        int n=nums.size();
        if (n==1) return nums[0];
        if (k>n) return -1; // More parititions than no. of elements available -> not possible

        int low = maxElement(nums, n);
        int high = sumElements(nums, n);
        int ans = low;
        while (low <= high) {
            int mid = low + (high - low)/2;
            if (noOfSubarraySplitsWithMaxSumMid(nums, mid, n) <= k) {
                ans = mid;
                high = mid-1;
            } 
            else {
                low = mid+1;
            }
        }
        return ans;
    }

    int noOfSubarraySplitsWithMaxSumMid(vector<int>& nums, int mid, int n) {
        int noOfSubarraysPossible = 1;
        int currSum = 0;
        int i=0;
        while (i<n) {
            if (currSum + nums[i] <= mid) {
                currSum += nums[i];
                i++;
            } else {
                currSum = 0;
                noOfSubarraysPossible++;
            }
        }
        return noOfSubarraysPossible;
    }

    int maxElement(vector<int>& nums, int n) {
        int maxElement = INT_MIN;
        for (int i=0; i<n; i++) {
            maxElement = max(maxElement, nums[i]);
        }
        return maxElement;
    }

    int sumElements(vector<int>& nums, int n) {
        int sum = 0;
        for (int i: nums) {
            sum += i;
        }
        return sum;
    }
};