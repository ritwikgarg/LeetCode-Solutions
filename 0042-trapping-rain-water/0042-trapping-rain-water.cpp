class Solution {
public:
    int trap(vector<int>& height) {
        //Idea: maintain a stack that stores the nge for every index
        int n = height.size();

        stack<int> st;
        int water = 0;

        for (int i=0; i<n; i++) {

            while(!st.empty() && height[st.top()] < height[i]) {
                int currHeight = height[st.top()];
                st.pop();
                if (st.empty()) break;
                water += (min(height[st.top()], height[i]) - currHeight) * (i-st.top()-1);
            }

            st.push(i);
        }

        return water;
    }
};