class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> monotonicStack;
        vector<int> nge;
        int n = nums.size();

        for (int i=2*n-1; i>=0; i--) {
            // Perform 2 passes over the array, first pass to populate the monotonic stack to allow for circular
            // searching, second pass to populate the stack for regular searching
            if (i/n >= 1) {
                while(monotonicStack.empty() != true && monotonicStack.top() <= nums[i%n]) {
                    monotonicStack.pop();
                }
                monotonicStack.push(nums[i%n]);
            } else {
                while(monotonicStack.empty() != true && monotonicStack.top() <= nums[i]) {
                    monotonicStack.pop();
                }
                if(monotonicStack.empty() == true) {
                    nge.insert(nge.begin(), -1);
                } else {
                    nge.insert(nge.begin(), monotonicStack.top());
                }
                monotonicStack.push(nums[i]);

            }
        }

        return nge;
    }
};