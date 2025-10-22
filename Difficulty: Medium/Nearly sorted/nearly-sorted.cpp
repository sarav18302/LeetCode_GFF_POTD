class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code here
         priority_queue<int, vector<int>, greater<int>>pq;
        int n=arr.size();
        int ind=0;
        for(int i=0; i<n; i++){
            pq.push(arr[i]);
            if(pq.size()>k){
                arr[ind]=pq.top();
                ind++;
                pq.pop();
            }
        }
        
        while(!pq.empty()){
            arr[ind]=pq.top();
            ind++;
            pq.pop();
        }
    }
};