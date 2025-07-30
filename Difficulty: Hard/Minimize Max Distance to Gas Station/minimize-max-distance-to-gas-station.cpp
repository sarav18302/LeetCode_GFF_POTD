class Solution {
  public:
    long double max(double a, int b)
    {
        return a>b? a:b;
    }
    int CountStations(vector<int> &stations, long double val)
    {
        int cnt = 0;
        for(int i = 1;i<stations.size();i++)
        {
            int t = int((stations[i] -stations[i-1])/val);
            // if((stations[i] -stations[i-1])%val == 0)
            // t--;
            cnt+=t;
        }
        return cnt;
    }
    double findSmallestMaxDist(vector<int> &stations, int k) {
        // Code here
       long double l=0,r=0;
        int n = stations.size();
        for(int i =1;i<n;i++)
        {
            r = max(r,(long double)(stations[i] - stations[i-1]));
        }
        long double diff = 1e-6;
        long double ans = -1;
        while(r-l > diff)
        {
            
           long double mid = (l+r)/2.0;
        //   cout<<mid<<endl;
            int val = CountStations(stations,mid);
            if(val>k)
            {
                l = mid;
            }
            else
            {
                ans = mid;
                r = mid;
            }
        }
        return r;
    }
};