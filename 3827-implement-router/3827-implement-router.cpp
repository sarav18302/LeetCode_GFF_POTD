class Router {
public:
    int capacity;
    queue<vector<int>>q;
    set<vector<int>> s;
    map<int,vector<int>> timestamps;
    map<int,int> tracker;
    Router(int memoryLimit) {
        capacity = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        
        if(s.count({source,destination,timestamp})>0)
        return false;
        q.push({source,destination,timestamp});
        s.insert({source,destination,timestamp});
        timestamps[destination].push_back(timestamp);
        while(q.size()>capacity)
        {
            auto ele = q.front();
            q.pop();
            tracker[ele[1]]++;
            s.erase(ele);
        }
        return true;
    }
    
    vector<int> forwardPacket() {
        if(q.size()>0)
        {
            auto ele = q.front();
            q.pop();
            tracker[ele[1]]++;
            s.erase(ele);
            return ele;
        }
        return {};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        if(timestamps.find(destination) == timestamps.end())
        return 0;
        auto &p = timestamps[destination];
        int temp = tracker[destination];
        auto right = lower_bound(p.begin() + temp, p.end(), startTime);
        auto left = upper_bound(p.begin() + temp, p.end(), endTime);
        return int(left - right);
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */