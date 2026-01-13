class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Idea: BS over how many elements we should take from the first array inorder to form a globally sorted
        // combination.

        int m = nums1.size();
        int n = nums2.size();
        int total = m+n;

        if (m>n) return findMedianSortedArrays(nums2, nums1);

        int low = -1;
        int high = m-1;

        while (low <= high) {
            int idxOfLastElementFromNums1 = low + (high-low)/2;
            int idxOfLastElementFromNums2 = ((total+1)/2) - (idxOfLastElementFromNums1 + 2);

            int l1 = (idxOfLastElementFromNums1 == -1) ? INT_MIN : nums1[idxOfLastElementFromNums1];
            int l2 = (idxOfLastElementFromNums2 == -1) ? INT_MIN : nums2[idxOfLastElementFromNums2];
            int r1 = (idxOfLastElementFromNums1 == m-1) ? INT_MAX : nums1[idxOfLastElementFromNums1+1];
            int r2 = (idxOfLastElementFromNums2 == n-1) ? INT_MAX : nums2[idxOfLastElementFromNums2+1];

            if (l1 <= r2 && l2 <= r1) {
                if (total%2 == 0) {
                    return (double)(max(l1,l2) + min(r1,r2))/2.0;
                } else {
                    return max(l1,l2);
                }
            } else if (l1 > r2) {
                high = idxOfLastElementFromNums1-1;
            } else {
                low = idxOfLastElementFromNums1+1;
            }
        }
        return 0.0;
    }
};