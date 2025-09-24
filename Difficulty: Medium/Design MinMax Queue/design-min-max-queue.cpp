class SpecialQueue {

  public:
    queue<int> q;
    set<int>s;
    map<int,int>mp;
    void enqueue(int x) {
        // Insert element into the queue
        q.push(x);
        mp[x]++;
        s.insert(x);
    }

    void dequeue() {
        // Remove element from the queue
        int ele = q.front();
        q.pop();
        mp[ele]--;
        if(mp[ele] == 0)
        s.erase(ele);
    }

    int getFront() {
        // Get front element
        return q.front();
    }

    int getMin() {
        // Get minimum element
        int ele = *(s.begin());
        return ele;
    }

    int getMax() {
        // Get maximum element
        int ele = * prev(s.end());
        return ele;
    }
};