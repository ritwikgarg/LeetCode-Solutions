class StockSpanner {
public:
    StockSpanner() : size(0) {
        
    }
    
    int next(int price) {   
        while (!st.empty() && st.top().first <= price) {
            st.pop();
        }
        int pgeIdx = (st.empty()) ? -1 : st.top().second;
        st.push({price, size});
        return (size++) - pgeIdx;
    }
private:
    stack<pair<int,int>> st; // Stores a val, idx pair.
    int size;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */