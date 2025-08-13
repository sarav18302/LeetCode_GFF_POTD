class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int cap;
    KthLargest(int k, vector<int>& nums) {
        cap = k;
        for(auto x: nums)
        pq.push(x);
    }
    int findKLargest()
    {
        while(pq.size() > cap)
        pq.pop();
        return pq.top();
    }
    int add(int val) {
        pq.push(val);
        return findKLargest();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */