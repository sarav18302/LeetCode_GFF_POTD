class StockSpanner {
public:
    stack<pair<int,int>>st;
    StockSpanner() {
        
    }
    // {60,1},{80,1},{100,1}
    int next(int price) {
        if(st.empty() || st.top().first >price)
        {
            st.push({price,1});
            return 1;
        }
        int temp =0;
        while(!st.empty() && st.top().first <=price)
        {
            temp+=st.top().second;
            st.pop();
        }
        st.push({price,temp+1});
        return temp+1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */