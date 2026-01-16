class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // Idea: maintain a doubly-ended queue, wich acts as a monotonic stack (largest element at bottom, smallest
        // element at top). Whenever we exceed window size, pop from the bottom. Always push from the top, as long
        // as element being pushed is smaller than element currently at top.

        deque<int> dqIdx;
        int n = nums.size();
        vector<int> ans;

        for (int i=0; i<n; i++) {
            while (!dqIdx.empty() && nums[dqIdx.back()] < nums[i]) {
                dqIdx.pop_back();
            }
            if (!dqIdx.empty() && dqIdx.front() < i-k+1) {
                dqIdx.pop_front();
            }
            if (i >= k-1) {
                int largestElementInWindowIdx = (dqIdx.empty()) ? i : dqIdx.front();
                ans.push_back(nums[largestElementInWindowIdx]);
            }
            dqIdx.push_back(i);
        }
        return ans;
    }
};