class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        int total = m+n;
        if (m > n) return findMedianSortedArrays(nums2, nums1);

        int low = -1;
        int high = m-1;

        while (low <= high) {
            int cut1 = low + (high-low)/2; // last index in left half from nums1
            int cut2 = (total+1)/2 - (cut1 + 1) - 1; // last index in left half from nums2

            int l1 = (cut1 == -1) ? INT_MIN : nums1[cut1];
            int l2 = (cut2 == -1)  ? INT_MIN : nums2[cut2];
            int r1 = (cut1 == m-1) ? INT_MAX: nums1[cut1+1];
            int r2 = (cut2 == n-1) ? INT_MAX: nums2[cut2+1];

            if (l1 <= r2 && l2 <= r1) {
                if (total%2 == 0) {
                    return (double) (max(l1, l2) + min(r1, r2))/2;
                } else {
                    return max(l1, l2);
                }
            }

            else if (l1 > r2) {
                high = cut1 - 1;
            }

            else if (l2 > r1) {
                low = cut1 + 1;
            }

        }
        return -1;
    }
};