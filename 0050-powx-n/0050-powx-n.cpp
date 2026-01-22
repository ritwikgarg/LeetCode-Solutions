class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;              // widen first
        if (N < 0) {
            x = 1.0 / x;
            N = -N;                   // safe now
        }
        return calculatePow(1, x, N);
    }

    double calculatePow(double ans, double x, long long n) {
        if (n == 0) return ans;

        if (n % 2 == 1) {   // odd
            ans *= x;
            n -= 1;
        }
        // now n is even
        return calculatePow(ans, x * x, n / 2);
    }
};