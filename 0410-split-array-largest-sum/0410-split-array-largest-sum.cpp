class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        // Idea: answer space is sum of subarrays and we want to minimize that sum
        // For a given largest sum, see if we can make k subarrays
        // If we can make less that equal to k subarrays, then answer is possible (since it can be split into k)
        // If we make more than k subarrays then we need to increase largest sum allowed

        int n = nums.size();
        int maxSum = 0;
        
        int low = maxElement(nums);
        int high = sumElements(nums);
        int ans = high;

        while (low <= high) {
            int mid = low + (high-low)/2;

            if (canParitionIntoKSubarraysWithGivenMaxSum(nums, k, mid)) {
                ans = mid;
                high = mid - 1;
            }

            else {
                low = mid + 1;
            }
        }
        return ans;
    }

    bool canParitionIntoKSubarraysWithGivenMaxSum(vector<int>& nums, int k, int maxSumAllowed) {
        int noOfParitions = 1;
        int sum = 0;

        int i = 0;
        while (i < nums.size()) {
            sum += nums[i];
            if (sum <= maxSumAllowed) {
                i++;
            } else {
                noOfParitions++;
                if (noOfParitions > k) {
                    return false;
                }
                sum = nums[i];
                i++;
            }
        }

        if (noOfParitions <= k) {
            return true;
        }
        return false;
    }

    int maxElement(vector<int>& nums) {
        int maxElem = nums[0];
        for (int i:nums) {
            maxElem = max(i, maxElem);
        }
        return maxElem;
    }

    int sumElements(vector<int>& nums) {
        int sum = 0;
        for (int i:nums) {
            sum += i;
        }
        return sum;
    }
}; 