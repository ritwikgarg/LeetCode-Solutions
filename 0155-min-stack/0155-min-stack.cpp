class MinStack {
public:
    MinStack(): minVal(0) {
        
    }
    
    void push(int val) {
        if (st.empty()) {
            minVal = val;
            st.push(0);
        }
        else if (minVal > val) {
            long long diff = 1LL*val - minVal;
            minVal = val;
            st.push(diff);
        } else {
            long long diff = 1LL*val - minVal;
            st.push(diff);
        }
    }
    
    void pop() {
        if (st.top() < 0) {
            minVal = minVal - st.top();
        }
        st.pop();
    }
    
    int top() {
         if (st.top() < 0) {
            return (int)minVal;
        } else {
            return (int)(st.top() + minVal);
        }
    }
    
    int getMin() {
        return (int)minVal;
    }
private:
    long long minVal;
    stack<long long> st;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */