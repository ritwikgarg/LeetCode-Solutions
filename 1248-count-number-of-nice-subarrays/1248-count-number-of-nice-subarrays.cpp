class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> temp(n,0);
        for (int i=0; i<n; i++) {
            temp[i] = nums[i]%2; // 0 if even, 1 if odd
        }
        return countSubarraysWithSumLessThanEqualToK(temp, k) - countSubarraysWithSumLessThanEqualToK(temp, k-1);
    }

    int countSubarraysWithSumLessThanEqualToK(vector<int>& nums, int goal) {
        int left = 0;
        int right = 0;
        int n = nums.size();
        int sum = 0;
        int count = 0;
        while (right < n) {
            sum += nums[right];
            while (sum > goal) {
                sum -= nums[left];
                left++;
            }
            count += right - left + 1;
            right++;
        }
        return count;
    }
};