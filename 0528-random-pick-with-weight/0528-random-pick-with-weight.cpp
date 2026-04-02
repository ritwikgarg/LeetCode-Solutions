class Solution {
public:
    Solution(vector<int>& w) {
        int n = w.size();
        for (int i=0; i<n; i++) {
            total += (long long)w[i];
            prefix.push_back(total);
        }
    }
    
    int pickIndex() {
        long long target = rand() % total + 1;
        int low = 0;
        int high = prefix.size() - 1;
        int ans = 0;
        while (low <= high) {
            int mid = low + (high-low)/2;
            if (prefix[mid] < target) {
                low = mid+1;
            } else {
                high = mid-1;
                ans = mid;
            }
        }
        return ans;
    }

private:
    vector<long long> prefix;
    long long total = 0;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */