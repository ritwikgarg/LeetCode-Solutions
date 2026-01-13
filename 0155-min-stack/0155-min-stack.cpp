class MinStack {
private:
    stack<long long> st;      // ✅ must be long long
    long long minVal = LLONG_MAX;

public:
    MinStack() {}

    void push(int val) {
        long long x = val;

        if (st.empty()) {
            minVal = x;
            st.push(x);
            return;
        }

        if (x >= minVal) {
            st.push(x);
        } else {
            st.push(2LL * x - minVal);  // encoded marker
            minVal = x;
        }
    }

    void pop() {
        if (st.empty()) return;

        long long poppedElem = st.top(); // ✅ long long
        st.pop();

        if (poppedElem < minVal) {
            minVal = 2LL * minVal - poppedElem; // restore previous min
        }

        if (st.empty()) minVal = LLONG_MAX; // optional, keeps getMin safe
    }

    int top() {
        if (st.empty()) return -1;

        long long topElem = st.top(); // ✅ long long
        if (topElem >= minVal) return (int)topElem;
        return (int)minVal;
    }

    int getMin() {
        if (st.empty()) return -1;
        return (int)minVal;
    }
};
