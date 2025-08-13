class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize)
        return false;
        map<int,int>mp;
        for(auto x:hand)
        mp[x]++;
        priority_queue<pair<int,int>>pq;
        for(auto x: mp)
        pq.push({x.first,x.second});
        while(!pq.empty() )
        {
            vector<pair<int,int>> remain;
            int val = pq.top().first;
            int freq = pq.top().second;
            pq.pop();
            if(freq>1)
            remain.push_back({val,freq-1});
            // cout<<val<<endl;
            for(int i =1;i<groupSize;i++)
            {
                int ele = pq.top().first;
                int cnt = pq.top().second;
                pq.pop();
                // cout<<ele<<endl;
                if(val-i != ele )
                return false;
                else
                {
                    if(cnt>1)
                    remain.push_back({ele,cnt-1});
                }
            }
            for(auto x: remain)
            pq.push(x);
           
        }
        return true;
    }
};