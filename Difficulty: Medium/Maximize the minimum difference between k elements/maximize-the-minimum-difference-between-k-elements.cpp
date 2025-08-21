class Solution {
  public:
    bool isPossible(vector<int>& arr, int k, int val)
    {
        int last = arr[0];
        int cnt = 1;
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]-last >=val)
            {
                cnt++;
                last = arr[i];
            }
            if(cnt ==k)
            return true;
        }
        return false;
        
    }
    int maxMinDiff(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int low = 0;
        int high = arr.back() - arr.front();
        int ans = 0;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(isPossible(arr,k,mid))
            {
                ans = mid;
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
        return ans;
    }
};
