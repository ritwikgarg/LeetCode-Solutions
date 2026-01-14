class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> monotonicStack;
        unordered_map<int, int> elems;

        int m = nums1.size();
        int n = nums2.size();

        for (int i=0; i<m; i++) {
            elems.insert({nums1[i], 0}); //Inserting into set for O(1) lookups
        }

        // Populating the monotonic stack
        for (int i=n-1; i>=0; i--) {
            
            while (monotonicStack.empty() != true && nums2[i] >= monotonicStack.top()) {
                monotonicStack.pop();
            }

            if ((monotonicStack.empty() == true) && (elems.find(nums2[i]) != elems.end())) {
                elems[nums2[i]] = -1;
            } else if (elems.find(nums2[i]) != elems.end()) {
                elems[nums2[i]] = monotonicStack.top();
            }

            monotonicStack.push(nums2[i]);
        }

        vector<int> ans;
        for (int it: nums1) {
            ans.push_back(elems[it]);
        }

        return ans;
    }
};