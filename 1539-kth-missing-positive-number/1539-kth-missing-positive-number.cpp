class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // Idea: count of missing numbers up to an index 'i' is arr[i] - (i+1)
        // So just binary search through the array, checking how many numbers are missing at mid index
        // If that count happens to be >=k , then the answer could lie between arr[mid-1] and arr[mid]
        // If that count is < k, then the answer is later in the array and increase mid

        int n = arr.size();
        if (k < arr[0]) return k;
        if (k > (arr[n-1]-n)) return arr[n-1]+(k-(arr[n-1]-n));
        int low = 0;
        int high = n-1;
        int ans = -1;

        while(low <= high) {
            int mid = low + (high - low)/2;
            int countOfNosMissingAtMid = arr[mid] - (mid+1);

            if (countOfNosMissingAtMid >= k) {
                ans = arr[mid-1] + (k-(arr[mid-1]-mid));
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return ans;
    }
};