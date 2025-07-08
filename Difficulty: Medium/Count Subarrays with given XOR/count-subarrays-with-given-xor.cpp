class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        int ans = 0;
        int n = arr.size();
        map<int,int>mp;
        int xr = 0;
        mp[xr]++;
        for(int i =0;i<n;i++)
        {
            xr ^= arr[i];
            int x = xr^k;
            ans+=mp[x];
            mp[xr]++;
        }
        return ans;
    }
};