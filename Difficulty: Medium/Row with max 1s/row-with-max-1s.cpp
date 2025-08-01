// User function template for C++
class Solution {
  public:
    int helper(vector<vector<int>> &arr, int idx)
    {
        int n = arr[0].size();
        int ans = -1;
        int l = 0, r= n-1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(arr[idx][mid] == 1)
            {
                ans = mid;
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        return ans == -1? -1e9: n-ans;
    }
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int ans = -1e9, idx = -1;
        int n = arr.size();
        for(int i =0;i<n;i++)
        {
            int val = helper(arr,i);
            // cout<<i<<" "<<val<<endl;
            if(ans <val)
            {
                ans = val;
                idx = i;
            }
        }
        return idx;
    }
};