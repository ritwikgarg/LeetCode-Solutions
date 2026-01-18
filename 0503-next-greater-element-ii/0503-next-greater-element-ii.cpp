class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // Idea: double the array, where after the last element, the entire array repeats again
        int n = nums.size();
        stack<int> st;
        vector<int> nge (n, 0);

        for (int i=2*n-1; i>=0; i--) {
            if (i/n >= 1) {
                // In the first pass populate the stack
                while(!st.empty() && st.top() <= nums[i%n]) {
                    st.pop();
                }
                st.push(nums[i%n]);
            } else {
                while(!st.empty() && st.top() <= nums[i]) {
                    st.pop();
                }
                nge[i] = (st.empty()) ? -1 : st.top();
                st.push(nums[i]);
            }
        }
        return nge;
    }
};