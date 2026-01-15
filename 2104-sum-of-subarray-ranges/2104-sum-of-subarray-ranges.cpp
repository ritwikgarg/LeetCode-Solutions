class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        return sumOfSubarrayMaxmimums(nums) - sumOfSubarrayMinimums(nums);
    }

    long long sumOfSubarrayMaxmimums(vector<int>& nums) {
        // For a given element in nums, how many subarrays is it a part of where it the largest element
        // Mantain 2 arrays -> prev[i] and next[i] which contain the indices in the array for element at index i
        // such that going to or beyond prev[i] and next[i] will no longer makes nums[i] the largest in the subarray
        vector<int> next = findIdxOfNextLargestElement(nums);
        vector<int> prev = findIdxOfPrevLargestOrEqualElement(nums);

        long long sum = 0;
        int n = nums.size();
        for (int i=0; i<n; i++) {
            int left = i - prev[i];
            int right = next[i] - i;

            sum += left * right * 1LL * nums[i];
        }
        return sum;
    }

    vector<int> findIdxOfNextLargestElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> nleIdx (n, 0);
        stack<int> monotonicStack;

        for (int i=n-1; i>=0; i--) {
            while (!monotonicStack.empty() && nums[monotonicStack.top()]  <= nums[i]) {
                monotonicStack.pop();
            }
            nleIdx[i] = (monotonicStack.empty()) ? n : monotonicStack.top();
            monotonicStack.push(i);
        }
        return nleIdx;
    }

    vector<int> findIdxOfPrevLargestOrEqualElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> pleeIdx (n, 0);
        stack<int> monotonicStack;

        for(int i=0; i<n; i++) {
            while (!monotonicStack.empty() && nums[monotonicStack.top()] < nums[i]) {
                monotonicStack.pop();
            }
            pleeIdx[i] = (monotonicStack.empty()) ? -1 : monotonicStack.top();
            monotonicStack.push(i);
        }
        return pleeIdx;
    } 

    long long sumOfSubarrayMinimums(vector<int>& nums) {
        // For a given element in nums, how many subarrays is it a part of where it is the smallest element
        // Mantain 2 arrays -> prev[i] and next[i] which contain the indices in the array for element at index i
        // such that going to or beyond prev[i] and next[i] will no longer make nums[i] the smallest in the subarray
        vector<int> next = findIdxOfNextSmallestElement(nums);
        vector<int> prev = findIdxOfPrevSmallestOrEqualElement(nums);
        long long sum = 0;
        int n = nums.size();
        for (int i=0; i<n; i++) {
            int left = i - prev[i];
            int right = next[i] - i;
            
            sum = sum + (left * right * 1LL * nums[i]);
        }
        return sum;
    }

    vector<int> findIdxOfNextSmallestElement(vector<int>& nums) {
        int n = nums.size();
        stack<int> monotonicStack; // stores indexes of elements 
        vector<int> nseIdx(n, 0);
        for (int i=n-1; i>=0; i--) {
            while (!monotonicStack.empty() && nums[monotonicStack.top()] >= nums[i]) {
                monotonicStack.pop();
            }
            nseIdx[i] = (monotonicStack.empty()) ? n : monotonicStack.top();
            monotonicStack.push(i);
        }
        return nseIdx;
    }

    vector<int> findIdxOfPrevSmallestOrEqualElement(vector<int>& nums) {
        int n = nums.size();
        stack<int> monotonicStack; // stores indexes of elements
        vector<int> pseeIdx(n, 0);
        for (int i=0; i<n; i++) {
            while (!monotonicStack.empty() && nums[monotonicStack.top()] > nums[i]) {
                monotonicStack.pop();
            }
            pseeIdx[i] = (monotonicStack.empty()) ? -1 : monotonicStack.top();
            monotonicStack.push(i);
        }
        return pseeIdx;
    }
};