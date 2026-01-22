class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // Same idea as Moore's voting algo. Keep a track of 2 elems that could potentially be the majority element.
        // Since we want > n/3 times, there can only be 2 elements that can be the majority.
        int elem1 = 0, elem2 = 0;
        int cnt1 = 0, cnt2 = 0;
        int n = nums.size();

        for (int i=0; i<n; i++) {
            int currNum = nums[i];
            if (currNum == elem1) {
                cnt1++;
            } else if (currNum == elem2) {
                cnt2++;
            } else if (cnt1 == 0 && currNum != elem2) {
                cnt1 = 1;
                elem1 = currNum;
            } else if (cnt2 == 0 && currNum != elem1) {
                cnt2 = 1;
                elem2 = currNum;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0, cnt2 = 0;
        vector<int> ans;
        for (int i=0; i<n; i++) {
            if (nums[i] == elem1) {
                cnt1++;
            } else if (nums[i] == elem2) {
                cnt2++;
            }
        }

        if (cnt1 > n/3) {
            ans.push_back(elem1);
        }

        if (cnt2 > n/3) {
            ans.push_back(elem2);
        }

        return ans;
    }
};