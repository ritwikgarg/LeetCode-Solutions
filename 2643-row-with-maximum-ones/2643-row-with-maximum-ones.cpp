class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int maxCnt = -1;
        int index = -1;
        for (int i=0; i<m; i++) {
            int cnt = 0;
            cnt = cnt1sInGivenRow(mat[i]);
            if (cnt > maxCnt) {
                maxCnt = cnt;
                index = i;
            }
        }
        return {index, maxCnt};
    }

    int cnt1sInGivenRow(vector<int> nums) {
        int n = nums.size();
        sort (nums.begin(), nums.end());
        // BS over the row, looking for the first occurrence of 1
        int low = 0;
        int high = n-1;

        int idx = -1;
        while (low <= high) {
            int mid = (low + high)/2;
            if (nums[mid] == 1) {
                idx = mid;
                high = mid - 1;
            } else {
                low  = mid+1;
            }
        }

        if (idx == -1) return 0;
        return n-idx;
    }
};