class Solution {
  public:
    bool CanPlace(vector<int> &stalls, int val,int k)
    {
        int last = stalls[0];
        int cnt = 1;
        for(int i =1;i<stalls.size();i++)
        {
            if(stalls[i] - last >= val)
            {
                cnt++;
                last = stalls[i];
            }
        }
        if(cnt >= k) return true;
        return false;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        sort(stalls.begin(),stalls.end());
        int n = stalls.size();
        int l = 1, r= stalls[n-1] - stalls[0];
        int ans = -1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            bool val = CanPlace(stalls,mid,k);
            if(val)
            {
                ans = mid;
                l = mid+1;
            }
            else
            {
                r = mid-1;
                
            }
        }
        return ans;
    }
};