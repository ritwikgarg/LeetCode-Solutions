#include <stack>

class MyQueue {
private:
    stack <int> s1;
    stack <int> s2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        // 1. Remove everything from s1 and put into s2
        while (s1.empty() != true) {
            s2.push(s1.top());
            s1.pop();
        }

        // 2. Insert new element into s1
        s1.push(x);

        // 3. Reinsert everything in s2 into s1
        while (s2.empty() != true) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int val = s1.top();
        s1.pop();
        return val;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.size() == 0 ? true : false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */