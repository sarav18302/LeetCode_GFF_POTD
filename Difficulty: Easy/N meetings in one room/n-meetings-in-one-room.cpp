class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        vector<pair<int,int>> interval;
        int n = start.size();
        for(int i =0;i<n;i++)
        interval.push_back({end[i],start[i]});
        sort(interval.begin(),interval.end());
        int st=interval[0].second;
        int et = interval[0].first;
        int cnt = 1;
        for(int i =1;i<n;i++)
        {
            if(et<interval[i].second)
            {
                st =  interval[i].second;
                et = interval[i].first;
                cnt++;
            }
        }
        return cnt;
    }
};