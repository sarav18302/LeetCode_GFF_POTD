// User function template for C++

class Solution {
  public:
    int CountPainters(vector<int>& arr,int val)
    {
        int sum = 0, cnt =1;
        for(int i =0;i<arr.size();i++)
        {
            if(sum+arr[i] <= val)
            {
                sum+=arr[i];
            }
            else
            {
                cnt++;
                sum =arr[i];
            }
        }
        return cnt;
    }
    int minTime(vector<int>& arr, int k) {
        // code here
        
        // return minimum time
        int n = arr.size();
        int l = *max_element(arr.begin(),arr.end());
        int r = accumulate(arr.begin(),arr.end(),0);
        int ans = -1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            int val = CountPainters(arr,mid);
            if(val> k)
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