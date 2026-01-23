class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        int inflectionIndex = n-1;

        for (int i=n-1; i>=1; i--) {
            if (nums[i]<=nums[i-1]) {
                inflectionIndex--;
            } else {
                break;
            }
        }

        if (inflectionIndex == 0) {
            return reverse(nums.begin(), nums.end());
        }

        for (int i=n-1; i>= inflectionIndex; i--) {
            if (nums[i] > nums[inflectionIndex-1]) {
                swap(nums[i], nums[inflectionIndex-1]);
                break;
            }
        }

        reverse(nums.begin()+inflectionIndex, nums.end());
    }
};