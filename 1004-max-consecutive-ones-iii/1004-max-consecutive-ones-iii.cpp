class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLen = 0;

        int left = 0;
        int right = 0;

        while (right < n) {
            int no = nums[right];
            if (no == 1) {
                right++;
            } else {
                if (k > 0) {
                    k--;
                    right++;
                } else {
                    while (left <= right && left < n) {
                        if (nums[left] == 0) {
                            left++;
                            k++;
                            break;
                        }
                        left++;
                    }
                }
            }

            int len = right-left;
            maxLen = max(len, maxLen);
        }
        return maxLen;
    }
};