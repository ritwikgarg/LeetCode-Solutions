class Solution {
public:
    string getPermutation(int n, int k) {
        vector<char> digitsAvailable;
        string ans = "";
        for (int i=1; i<=n; i++) {
            digitsAvailable.push_back('0'+i);
        }
        buildAns(ans, n, k, digitsAvailable);
        return ans;
    }

    void buildAns(string &ans, int n, int k, vector<char>& digitsAvailable) {
        if (n == 1) {
            ans += digitsAvailable[0];
            return;
        }
        int blockSize = factorial(n-1);

        int digitExcludedIndex = ((k-1)/blockSize);

        int digitExcluded = digitsAvailable[digitExcludedIndex];
        digitsAvailable.erase(digitsAvailable.begin() + digitExcludedIndex);

        ans += digitExcluded;
        k = (k-1) % blockSize + 1;

        buildAns(ans, n-1, k, digitsAvailable);
    }

    int factorial(int n) {
        int prod = 1;
        for (int i=n; i>=1; i--) {
            prod*=i;
        }
        return prod;
    }
};