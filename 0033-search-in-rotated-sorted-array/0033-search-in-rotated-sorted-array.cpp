class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Idea: start at mid, compare it with low and mid.
        // If mid > low and high > mid -> array is not rotated
        // If mid > low and high < mid -> left half is sorted
        // If mid < low and high > mid -> right half is sorted
        // See if the element lies in the sorted half, if yes discard the rest, else discard the sorted half
        int n = nums.size();
        int low = 0;
        int high = n-1;

        while (low <= high) {
            int mid = low + (high - low)/2;
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[low] <= nums[mid] && nums[mid] >= nums[high]) { //Left half sorted
                if (target >= nums[low] && target <= nums[mid]) {
                    high = mid-1;
                } else {
                    low = mid+1;
                }
            }
            else if (nums[mid] <= nums[high] && nums[low] >= nums[mid]) { // Right half sorted
                if (target >= nums[mid] && target <= nums[high]) {
                    low = mid+1;
                } else {
                    high = mid-1;
                }
            } else { // Whole array sorted
                if (target <= nums[mid]) {
                    high = mid-1;
                } else {
                    low = mid+1;
                }
            }

        }

        return -1;
    }
};