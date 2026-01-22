class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Idea: put all elements inside a set for O(1) lookups
        // Then iterate through the array checking if --currElem exists in the map or not
        // If it does, then the currNum cannot be the start of a sequence
        // If it does not, then currNum is the start of a sequence

        int n = nums.size();
        if (n==0) return 0;
        unordered_set <int> elemSet;

        for (int i=0; i<n; i++) {
            elemSet.insert(nums[i]);
        }

        int maxLen = 1;
        for (auto it: elemSet) {
            int len = 1;
            if (elemSet.find(it-1) != elemSet.end()) {
                continue;
            } else {
                while (elemSet.find(++it) != elemSet.end()) {
                    len++;
                }
            }
            maxLen = max(len, maxLen);
        }
        return maxLen;
    }
};