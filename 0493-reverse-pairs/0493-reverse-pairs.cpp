class Solution {
public:
    int reversePairs(vector<int>& nums) {

        return mergeSort(nums, 0, nums.size()-1);
    }

    int mergeSort(vector<int>& nums, int low, int high) {
        int totalCnt = 0;
        if (low >= high) {
            return totalCnt;
        }

        int mid = low + (high-low)/2;
        totalCnt += mergeSort(nums, low, mid);
        totalCnt += mergeSort(nums, mid+1, high);
        totalCnt += countPairs(nums, low, mid, high);
        merge(nums, low, mid, high);
        return totalCnt;
    }

    void merge(vector<int>& nums, int low, int mid, int high) {
        vector<int> temp;
        int left = low;
        int right = mid+1;

        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;
            } else {
                temp.push_back(nums[right]);
                right++;
            }
        }

        while (left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }

        while (right <= high) {
            temp.push_back(nums[right]);
            right++;
        }

        for (int i=low; i<=high; i++) {
            nums[i] = temp[i-low];
        }
    }

    int countPairs (vector<int>& nums, int low, int mid, int high) {
        int cnt = 0;
        int left = low;
        int right = mid+1;

        while (left<=mid && right<=high) {
            if ((long long)nums[left] > 2LL*nums[right]) {
                cnt += mid-left+1;
                right++;
            } else {
                left++;
            }
        }
        return cnt;
    }
};