class Solution {
public:
    int myAtoi(string s) {
        return helper(s, 0, 0LL, false, false, false);
    }

private:
    // idx: current index
    // mag: magnitude accumulated so far (non-negative), kept as long long
    // isNegative: sign
    // signSeen: have we consumed '+'/'-' yet
    // startedDigits: have we started reading digits yet
    int helper(const string& s, int idx, long long mag,
               bool isNegative, bool signSeen, bool startedDigits) {
        // Stop if end of string
        if (idx >= (int)s.size()) return finalize(mag, isNegative);

        char ch = s[idx];

        // Skip leading spaces only before sign/digits
        if (!startedDigits && !signSeen && ch == ' ') {
            return helper(s, idx + 1, mag, isNegative, signSeen, startedDigits);
        }

        // Optional sign (only once, before digits)
        if (!startedDigits && !signSeen && (ch == '+' || ch == '-')) {
            return helper(s, idx + 1, mag, ch == '-', true, startedDigits);
        }

        // Digit
        if (ch >= '0' && ch <= '9') {
            long long candidate = mag * 10 + (ch - '0');

            // Clamp while building (avoid overflow and handle INT_MIN correctly)
            if (!isNegative && candidate > (long long)INT_MAX) return INT_MAX;
            if (isNegative && candidate > 2147483648LL) return INT_MIN; // abs(INT_MIN)

            return helper(s, idx + 1, candidate, isNegative, signSeen, true);
        }

        // Any other char => stop parsing
        return finalize(mag, isNegative);
    }

    int finalize(long long mag, bool isNegative) {
        long long val = isNegative ? -mag : mag;
        if (val < (long long)INT_MIN) return INT_MIN;
        if (val > (long long)INT_MAX) return INT_MAX;
        return (int)val;
    }
};
