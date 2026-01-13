class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        int n = nums.size();
        if (n==0) return 0;
        int maxCnt = 1;

        for (int i=0; i<n; i++) {
            st.insert(nums[i]);
        }

        for(auto it : st) {
            if(st.find(it-1) != st.end()) {
                continue;
            } else {
                int cnt = 1;
                int next = it+1;
                while(st.find(next) != st.end()) {
                    cnt++;
                    next++;
                }
                maxCnt = max(maxCnt, cnt);
            }
        }

        return maxCnt;
    }
};