class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        vector<int> nextSmallestElementIndex = findNextSmallestElementIndex(arr);
        vector<int> prevSmallestOrEqualElementIndex = findPreviousSmallestOrEqualElementIndex(arr);

        int sum = 0;
        int mod = (int)1e9+7;
        for (int i=0; i<n; i++) {
            int left = i - prevSmallestOrEqualElementIndex[i];
            int right = nextSmallestElementIndex[i] - i;

            sum = (sum + (left * right * 1LL * arr[i])%mod)%mod;
        }
        return sum;
    }

    vector<int> findPreviousSmallestOrEqualElementIndex(vector<int>& arr) {
        stack<int> monotonicStack; // Stack stores index of elements, not the elements themselves
        vector<int> prevSmallestOrEqualElementIndex (arr.size(),0);

        int n=arr.size();
        for (int i=0; i<n; i++) {
            while (!monotonicStack.empty() && arr[monotonicStack.top()] > arr[i]) { //Note there is no equal here
                monotonicStack.pop();
            }
            prevSmallestOrEqualElementIndex[i] = (monotonicStack.empty()) ? -1 : monotonicStack.top();

            monotonicStack.push(i);
        }
        return prevSmallestOrEqualElementIndex;
    }

    vector<int> findNextSmallestElementIndex(vector<int>& arr) {
        stack<int> monotonicStack; // Stack stores index of elements, not the elements themselves
        vector<int> nextSmallestElementIndex (arr.size(), 0);

        int n=arr.size();
        for(int i=n-1; i>=0; i--) {
            while (!monotonicStack.empty() && arr[monotonicStack.top()] >= arr[i]) {
                monotonicStack.pop();
            }
            
            nextSmallestElementIndex[i] = (monotonicStack.empty()) ? n : monotonicStack.top();

            monotonicStack.push(i); 
        }

        return nextSmallestElementIndex;
    }
};