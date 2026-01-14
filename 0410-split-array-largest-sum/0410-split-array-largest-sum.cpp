class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        // Idea: BS will be on answer space of subarray sum
        // Smallest possible subarray sum will be equal to the largest element in the array (when k = n)
        // Largest possible subarray sum will be equal to the sum of all elements in the array (when k=1)

        // So, for a given 'maxSumAllowed' find out if k partitions can be made or not

        // If less than k partitions can be made, then k partitions can definitely be made, so answer is possible but
        // decrease maxSumAllowed in the hopes of finding a smaller answer

        // If more than k partitions can be made, that means the maxSumAllowed is too small and hence should be increased

        long long low = maxElement(nums);
        long long high = totalSum(nums);
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high-low)/2;
            if (canSplitIntoKSubarrays(nums, k, mid)) {
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return ans;
    }

    bool canSplitIntoKSubarrays(vector<int>& nums, int k, long long maxSumAllowed) {
        // Greedily start the first subarray from 0th element
        int noOfSubarrays = 1;
        long long sum  = 0;
        int i=0;
        while (i<nums.size()) {
            sum += nums[i];
            if (sum <= maxSumAllowed) {
                i++;
            } else {
                noOfSubarrays++;
                if (noOfSubarrays > k) {
                    return false;
                }
                sum = nums[i];
                i++;
            }
        }
        return true;
    }

    long long maxElement(vector<int>& nums) {
        int maxElem = INT_MIN;
        for (int i: nums) {
            maxElem = max(maxElem, i);
        }
        return (long long) maxElem;
    }

    long long totalSum(vector<int>& nums) {
        long long sum = 0;
        for (int i: nums) {
            sum += i;
        }
        return sum;
    }
};