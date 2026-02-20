class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map <int, int> freqMap;

        for (int i=0; i<n; i++) {
            freqMap[nums[i]]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for (auto &it : freqMap) {
            minHeap.push({it.second, it.first});
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        vector<int> ans;

        while (!minHeap.empty()) {
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return ans;
    }
};