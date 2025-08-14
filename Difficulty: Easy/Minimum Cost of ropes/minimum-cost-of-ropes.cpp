class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        int n = arr.size();
        if(n ==1)
        return 0;
        priority_queue<int,vector<int>,greater<int>>pq;
        int ropelength = 0;
        int ans = 0;
        for(int i =0;i<n;i++)
        {
            pq.push(arr[i]);
        }
        while(!pq.empty() && pq.size()>1)
        {
            int ele1= pq.top();
            pq.pop();
            int ele2 = pq.top();
            pq.pop();
            // cout<<ele1<<" "<<ele2<<endl;
            pq.push(ele1+ele2);
            ans+=(ele1+ele2);
            // cout<<ans<<" "<<ropelength<<endl;
        }
        return ans;
    }
};