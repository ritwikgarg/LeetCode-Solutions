class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> pseIdx = prevSmallerElementIdx(arr);
        vector<int> nseIdx = nextSmallerElementIdx(arr);

        int mod = 1e9+7;
        int minSum = 0;
        for (int i=0; i<n; i++) {
            minSum = (minSum+(((arr[i] * 1LL * (nseIdx[i] - i))%mod) * 1LL * (i - pseIdx[i]))%mod)%mod;
        }

        return minSum;
    }

    vector<int> nextSmallerElementIdx(vector<int>& nums) {
        stack<int> st; 
        int n = nums.size();
        vector<int> nseIdx (n, 0);

        for (int i=n-1; i>=0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }

            nseIdx[i] = (st.empty()) ? n : st.top();

            st.push(i);
        }
        return nseIdx;
    }

    vector<int> prevSmallerElementIdx(vector<int>& nums) {
        stack<int> st; //stores indices
        int n = nums.size();
        vector<int> pseIdx (n, 0);

        for (int i=0; i<n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }

            pseIdx[i] = (st.empty()) ? -1 : st.top();

            st.push(i);
        }

        return pseIdx;
    }


};