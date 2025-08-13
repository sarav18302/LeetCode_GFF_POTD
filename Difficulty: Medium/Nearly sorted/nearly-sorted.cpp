class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code
        priority_queue<int, vector<int>, greater<int>> minheap;
        for(int i =0;i<=k;i++)
        minheap.push(arr[i]);
        int idx = 0;
        for(int i = k+1;i<arr.size();i++)
        {
            arr[idx] = minheap.top();
            minheap.pop();
            idx++;
            minheap.push(arr[i]);
        }
        while(!minheap.empty())
        {
            arr[idx] = minheap.top();
            minheap.pop();
            idx++;
        }
    }
};