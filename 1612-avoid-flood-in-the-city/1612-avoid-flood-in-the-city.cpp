class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        set<int>zero;
        int n = rains.size();
        vector<int>ans(n,-1);
        map<int,int>mp;
        map<int,bool>filled;
        for(int i =0;i<n;i++)
        {
            if(rains[i] == 0)
            {
                zero.insert(i);
                ans[i] = 1;
                continue;
            }
            if(mp.count(rains[i]))
            {
                int lastIndex = mp[rains[i]];
                auto idx = zero.upper_bound(lastIndex);
                if(idx == zero.end())
                {
                    return {};
                }
                ans[*idx] = rains[i];
                zero.erase(idx);
                
            }
            mp[rains[i]] = i;
                
            
        }
        return ans;
    }
};