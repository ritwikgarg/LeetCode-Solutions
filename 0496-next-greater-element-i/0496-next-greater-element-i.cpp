class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> numbers;
        stack<int> st;
        vector<int> ans;

        for (int i=0; i<nums1.size(); i++) {
            numbers[nums1[i]] = 0;
        }

        int n = nums2.size();
        
        for (int i=n-1; i>=0; i--) {
            while(!st.empty() && st.top() < nums2[i]) {
                st.pop();
            }

            if(numbers.find(nums2[i]) != numbers.end()) {
                numbers[nums2[i]] = (st.empty()) ? -1 : st.top();
            }

            st.push(nums2[i]);
        }

        for (int i=0; i<nums1.size(); i++) {
            ans.push_back(numbers[nums1[i]]);
        }

        return ans;
    }
};