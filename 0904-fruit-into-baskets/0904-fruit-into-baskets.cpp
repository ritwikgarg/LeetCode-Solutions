class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int left = 0;
        int right = 0;
        unordered_map <int, int> freqMap; // stores no -> freq
        int maxLen = 0;
        while (right < n) {
            int no = fruits[right];
            if (freqMap.find(no) == freqMap.end()) { // No. doesn't exist in the map
                freqMap[no] = 1;
            } else {
                freqMap[no]++;
            }
            int uniqueNos = freqMap.size();
            if (uniqueNos > 2) {
                freqMap[fruits[left]]--;
                if (freqMap[fruits[left]] == 0) {
                    freqMap.erase(fruits[left]);
                }
                left++;
            }
            maxLen = max(maxLen, right-left+1);
            right++;
        }
        return maxLen;
    }
};