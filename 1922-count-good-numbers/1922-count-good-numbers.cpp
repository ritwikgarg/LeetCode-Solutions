class Solution {
public:
    static const long long MOD = 1000000007LL;

    long long modPow(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp%2 == 1) {
                res = (res*base)%MOD;
                exp = exp-1;
            } else {
                base = (base*base)%MOD;
                exp = exp/2;
            }
        }
        return res;
    }

    int countGoodNumbers(long long n) {
        long long evenCount = (n + 1) / 2; // positions 0,2,4,...
        long long oddCount  = n / 2;       // positions 1,3,5,...

        long long ans = (modPow(5, evenCount) * modPow(4, oddCount)) % MOD;
        return (int)ans;
    }
};
