class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map <int, int> prefixSumMap; // stores prefixSum -> count
        int count = 0;
        int n = nums.size();

        int sum = 0;
        for (int i=0; i<n; i++) {
            sum += nums[i];
            int want = sum - k;
            if (prefixSumMap.find(want) != prefixSumMap.end()) {
                count += prefixSumMap[want];
            }
            if (sum == k) {
                count++;
            }
            prefixSumMap[sum]++;
        }
        return count;
    }
};