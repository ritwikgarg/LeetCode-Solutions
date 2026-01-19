class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return countOfSubarraysWithLessThanOrEqualToKDistinct(nums, k) - countOfSubarraysWithLessThanOrEqualToKDistinct(nums, k-1);
    }

    int countOfSubarraysWithLessThanOrEqualToKDistinct(vector<int>& nums, int k) {
        if (k < 0) return 0;
        unordered_map<int, int> freqMap;
        int n = nums.size();
        int left = 0;
        int right = 0;
        int count = 0;

        while (right < n) {
            int no = nums[right];
            freqMap[no]++;
            while (freqMap.size() > k) {
                freqMap[nums[left]]--;
                if (freqMap[nums[left]] == 0) {
                    freqMap.erase(nums[left]);
                }
                left++;
            }
            if (freqMap.size() <= k) {
                count+= right-left+1;
            }
            right++;
        }
        return count;
    }
};