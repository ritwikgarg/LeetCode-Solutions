class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // O(log n) constraint indicates that we need to use binary search
        // idea would be to pick a mid element, check whether either the elem to the left or right is same as mid
        // if it is, then this element can't be the exactly once
        // if it isn't then this element is the exactly once one

        int n = nums.size();
        if (n==1) return nums[0];
        if (nums[0] != nums[1]) return nums[0];
        if (nums[n-1] != nums[n-2]) return nums[n-1];
        int low = 1;
        int high = n-2;

        while (low <= high) {
            int mid = low + (high-low)/2;
            
            if (nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) {
                return nums[mid];
            }

            else if ((mid%2 == 0 && (nums[mid] == nums[mid-1]) ||  (mid%2 == 1 && (nums[mid] != nums[mid-1])))) { // After the single element
                high = mid-1;
            }

            else if ((mid%2 == 1 && (nums[mid] == nums[mid-1])) || (mid%2 == 0 && (nums[mid] != nums[mid-1]))) { // Before the single element
                low = mid+1;
            }
        }
        return -1;
    }
};