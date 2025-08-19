class Solution {
  public:
    vector<int> farMin(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> suffixmin(n);
        suffixmin[n-1] = arr[n-1];
        for(int i =n-2;i>=0;i--)
        suffixmin[i] = min(suffixmin[i+1],arr[i]);
        vector<int> res(n);
        for(int i =0;i<n;i++)
        {
            int left = i+1,high = n-1, ans = -1;
            while(left <=high)
            {
                int mid = (left+high)/2;
                if(suffixmin[mid] < arr[i])
                {
                    left = mid+1;
                    ans = mid;
                }
                else
                high = mid-1;
            }
            res[i] = ans;
        }
        return res;
    }
};