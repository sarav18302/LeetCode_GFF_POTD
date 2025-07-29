class Solution {
  public:
    int findStudents(vector<int> &arr, int val)
    {
        long long cnt = 0;
        int scnt =1;
        for(int i =0;i<arr.size();i++)
        {
            if(cnt+arr[i]<=val)
            {
                cnt+=arr[i];
            }
            else
            {
                scnt++;
                cnt = arr[i];
            }
        }
        return scnt;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        int l = *max_element(arr.begin(),arr.end());
        int r = accumulate(arr.begin(), arr.end(), 0);
        int ans = -1;
        if(n< k)
        return -1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            int val = findStudents(arr,mid);
            if(val > k)
            {
                
                l = mid+1;
            }
            else
            {
                ans = mid;
                r = mid-1;
            }
        }
        return ans;
    }
};