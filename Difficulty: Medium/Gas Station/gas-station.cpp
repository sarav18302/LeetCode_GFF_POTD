class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        //  code here
        int tg = 0;
        int tc = 0;
        int n = gas.size();
        for(int i =0;i<n;i++)
        {
            tg+=gas[i];
            tc+=cost[i];
        }
        if(tg<tc)
        return -1;
        tg = 0;
        int start = 0;
        for(int i =0;i<n;i++)
        {
            tg+=(gas[i] - cost[i]);
            if(tg<0)
            {
                tg = 0;
                start = i+1;
                
            }
        }
        return start;
    }
};