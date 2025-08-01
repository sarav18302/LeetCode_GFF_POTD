class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int n1 = a.size(), n2 = b.size();
        if(n1>n2) return kthElement(b,a,k);
        int n = n1+n2;
        int left = k;
        int l = max(0,k-n2), r = min(k,n1);
        while(l<=r)
        {
            int mid1 = (l+r)/2;
            int mid2 = left - mid1;
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX,r2 = INT_MAX;
            if(mid1-1>=0)
            l1 = a[mid1-1];
            if(mid2-1>=0)
            l2 = b[mid2-1];
            if(mid1<n1)
            r1 = a[mid1];
            if(mid2<n2)
            r2 = b[mid2];
            
            if(l1<=r2 && l2<=r1)
            {
                return max(l1,l2);
            }
            else if(l1>r2)
            {
                r = mid1-1;
            }
            else
            l = mid1+1;
            
        }
        return 0;
    }
};