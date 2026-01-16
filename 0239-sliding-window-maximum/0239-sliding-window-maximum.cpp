class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //Idea: for each element, we ask can this element be the max element in any k-length window that it is a part of?
    //For this, we need the pleIdx and nleIdx for each element
        if (k==1) {
            return nums;
        }
        int n = nums.size();
        
        vector<int> nleIdx = nextLargerElementIndex(nums);
        vector<int> ans;

        int j=0;
        for (int left=0; left<=n-k; left++) {
            int right = left + k - 1;
            if (j < left) j = left;

            while (nleIdx[j] <= right) j = nleIdx[j];

            ans.push_back(nums[j]);
        }

        return ans;
    }

    vector<int> nextLargerElementIndex(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> nleIdx (n, 0);

        for (int i=n-1; i>=0; i--) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }
            nleIdx[i] = (st.empty()) ? n : st.top();
            st.push(i);
        }

        return nleIdx;
    }
};