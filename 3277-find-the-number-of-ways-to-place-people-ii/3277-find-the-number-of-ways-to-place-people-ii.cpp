class Solution {
public:
    static bool cmp(const vector<int>& p, const vector<int>& q){
        return (p[0]==q[0])?p[1]<q[1]:p[0]>q[0];// order by (x, >)
    }
    int numberOfPairs(vector<vector<int>>& points) {
         int n = points.size();
        int cnt = 0;
        sort(points.begin(),points.end(),cmp);
        for(int i =0;i<n-1;i++)
        {
            int y = INT_MAX, yi = points[i][1];
            for(int j = i+1;j<n;j++)
            {
                int  b = points[j][1];
                if(b>=yi && y>b)
                {
                    cnt++;
                    y = b;
                    if(yi == b) break;
                }
                
                
            }
        }
        return cnt;
    }
};