class Solution {
  public:
    int UpperBound(vector<int>&mat, int x)
    {
        int n = mat.size();
        int l =0, r= n-1;
        int ans = n;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(mat[mid] >= x)
            {
                ans = mid;
                 r = mid-1;
            }
            else
            l = mid+1;
           
        }
        return ans;
    }
    int CountSmaller(vector<vector<int>> &mat, int x)
    {
        int m= mat.size(), n = mat[0].size(),cnt = 0;
        for(int i =0;i<m;i++)
        {
            cnt+=UpperBound(mat[i], x);
            // cout<<UpperBound(mat[i], x)<<endl;
        }
        return cnt;
    }
    int median(vector<vector<int>> &mat) {
        // code here
        int m = mat.size(), n = mat[0].size();
        int low = INT_MAX, high = INT_MIN;
        for(int i =0;i<m;i++)
        {
            low = min(low,mat[i][0]);
            high = max(high,mat[i][n-1]);
        }
        int req = n*m/2;
        int ans = -1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            int val = CountSmaller(mat,mid);
            // cout<<mid<<" "<<val<<endl;
            if(val >req) high = mid-1;
            else
            {
                ans = mid;
                low = mid+1;
            }
        }
        return ans;
    }
};
