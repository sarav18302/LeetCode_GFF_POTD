class LRUCache {
public:
    map<int,int>cache,cnt;
    queue<int>st;
    int capacity;
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(cnt.find(key)==cnt.end())
        return -1;
        st.push(key);
        cnt[key]++;
        return cache[key];
    }
    
    void put(int key, int value) {
        // if(cache.size() == capacity)
        // {
        //     cache.erase(st.front());
        //     st.pop();
        // }
        cache[key] = value;
        st.push(key);
        cnt[key]++;
        while(cnt.size()> capacity)
        {
            int cur = st.front();
            st.pop();
            if(cnt[cur]-- == 1)
            cnt.erase(cur);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */