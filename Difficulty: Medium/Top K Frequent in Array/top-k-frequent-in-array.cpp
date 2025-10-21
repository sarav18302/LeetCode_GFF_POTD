class Solution {
  public:
    vector<int> topKFreq(vector<int> &arr, int k) {
        // Code here
        map<int,int>mp;
        for(auto x: arr)
        mp[x]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>>pq;
        for(auto [k,v]: mp)
        {
            pq.push({v,k});
        }
        vector<int>ans;
        while(!pq.empty()&& k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
