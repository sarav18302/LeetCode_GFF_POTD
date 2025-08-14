class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());
        int n = a.size();
        priority_queue<pair<int,pair<int,int>>>pq;
        set<pair<int,int>>vis;
        pq.push({a[0]+b[0],{0,0}});
        vis.insert({0,0});
        vector<int> res;
        while(res.size() < k)
        {
            int ele = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            if(x+1<n && vis.find({x+1,y})==vis.end())
            {
            pq.push({a[x+1]+b[y],{x+1,y}});
            vis.insert({x+1,y});
            }
            if(y+1<n && vis.find({x,y+1})==vis.end())
            {
            pq.push({a[x]+b[y+1],{x,y+1}});
            vis.insert({x,y+1});
            }
            res.push_back(ele);
        }
        return res;
    }
};