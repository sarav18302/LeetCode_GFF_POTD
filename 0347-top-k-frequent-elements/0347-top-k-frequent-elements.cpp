class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       priority_queue<pair<int,int>> pq;
        unordered_map<int,int>mp;
        for(auto x:nums)
        {
            mp[x]+=1;
        }
        
        for(auto x:mp)
        {
            pq.push({x.second,x.first});
        }
        vector<int> ans;
        for(int i=0;i<k;i++)
        {
            int ind = pq.top().second;
            pq.pop();
            ans.push_back(ind);
        }
        
        return ans;
            
    }
};