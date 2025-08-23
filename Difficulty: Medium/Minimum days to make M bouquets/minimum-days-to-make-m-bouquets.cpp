class Solution {
  public:
    bool checkBouquets(vector<int>& arr, int k, int m,int val)
    {
        int cnt = 0;
        int res = 0;
        int n = arr.size();
        for(int i =0;i<n;i++)
        {
            if(arr[i] <=val)
            cnt++;
            else
            cnt =0;
            if(cnt == k)
            {
                res++;
                cnt =0;
            }
        }
        return res>=m;
    }
    int minDaysBloom(vector<int>& arr, int k, int m) {
        // Code here
        int low = 1e9, high = -1e9;
        int n = arr.size();
        for(int i =0;i<n;i++)
        {
            low = min(low,arr[i]);
            high = max(high,arr[i]);
        }
        int ans = -1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(checkBouquets(arr,k,m,mid))
            {
                ans = mid;
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return ans;
    }
};