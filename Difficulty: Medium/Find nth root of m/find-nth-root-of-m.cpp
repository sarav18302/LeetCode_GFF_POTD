class Solution {
  public:
    int nthRoot(int n, int m) {
        // Code here
        int l = 0, r= m;
        int ans = -1;
        while(l<=r)
        {
            int mid = ((l+r)/2);
            if(pow(mid,n) == m)
            return mid;
            else if(pow(mid,n) < m)
            {
                l = mid+1;
            }
            else
            {
                r = mid-1;
            }
        }
        return -1;
    }
};