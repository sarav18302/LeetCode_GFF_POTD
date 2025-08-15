class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                       vector<int> &newInterval) {
        // code here
        intervals.push_back({newInterval[0],newInterval[1]});
        vector<vector<int>> ans;
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>>q;
        for(int i =0;i<intervals.size();i++)
        q.push({intervals[i][0],intervals[i][1]});
        while(!q.empty())
        {
            int x = q.top().first;
            int y = q.top().second;
            q.pop();
            // cout<<x<<" "<<y<<endl;
            if(ans.size()==0)
            ans.push_back({x,y});
            else
            {
                if(ans.back()[1] >= x )
                ans.back()[1] = max(y,ans.back()[1]);
                else 
                ans.push_back({x,y});
            }
        }
        return ans;
    }
};