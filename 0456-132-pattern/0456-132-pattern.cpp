class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        stack<int> st; // Stores potential 3rd
        int second = INT_MIN; // Stores potential 2nd

        for (int i=n-1; i>=0; i--) {
            if (!st.empty() && nums[i] < st.top() && nums[i] < second && st.top() > second) {
                return true;
            }
            
            while (!st.empty() && st.top() < nums[i]) {
                second = st.top();
                st.pop();
            }

            if (nums[i] > second) {
                st.push(nums[i]);
            }
        }   

        return false;

    }
};