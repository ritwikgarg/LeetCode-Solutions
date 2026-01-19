class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map <int, int> prefixSumMap; // stores sum -> count of that sum
        int n = nums.size();
        int left = 0;
        int right = 0;
        int sum = 0;
        int count = 0;
        while (right < n) {
            sum += nums[right];
            int want = sum - goal;
            if (prefixSumMap.find(want) != prefixSumMap.end()) {
                count+=prefixSumMap[want];
            }
            if (sum == goal) {
                count++;
            }
            prefixSumMap[sum]++;
            right++;
        }
        return count;
    }
};