class LFUCache {
public:
    map<int,int>cache,cnt;
     priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    int capacity,t =0;
    LFUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end())
        return -1;
        put(key,cache[key]);
        return cache[key];
    }
    
    void put(int key, int value) {
       if(cache.find(key) == cache.end() && cache.size() == capacity)
       {
            while(cache.size() == capacity)
            {
                auto x = pq.top();
                if(cnt[x.second.second] == x.first)
                {
                    cache.erase(x.second.second);
                    cnt.erase(x.second.second);
                }
                pq.pop();
            }
       }
       cache[key] = value;
       cnt[key]++;
       pq.push({cnt[key],{t++,key}});
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */