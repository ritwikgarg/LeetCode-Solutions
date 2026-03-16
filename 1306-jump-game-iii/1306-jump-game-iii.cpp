class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        return reachZero(arr, start);
    }

    bool reachZero(vector<int>& arr, int currIndex) {
        if (currIndex >= 0 && currIndex <= arr.size()-1 && arr[currIndex] == 0) {
            return true;
        }
        
        if (arr[currIndex] == -1) return false; // If we came back to this index, that means it didn't lead us to a 0

        int left = currIndex - arr[currIndex];
        int right = currIndex + arr[currIndex];

        arr[currIndex] = -1; // Mark current index as visited to prevent cycles

        if (left < 0 && right > arr.size() - 1) {
            return false;
        }

        bool leftBranch = false;
        bool rightBranch = false;

        if (left >= 0) {
            leftBranch = reachZero(arr, left);
        } 

        if (right <= arr.size() - 1) {
            rightBranch = reachZero(arr, right);
        }

        return leftBranch || rightBranch;
    }
};