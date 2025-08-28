class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        // code here
        int low =0, high = 0;
        int n = arr.size(),cnt =0;
        int ans =0;
        while(high<n)
        {
            if(arr[high] == 0)
            {
                cnt++;
                while(cnt>k)
                {
                    if(arr[low] == 0)
                    cnt--;
                    low++;
                }
            }
            ans = max(ans,high-low+1);
            high++;
        }
        return ans;
    }
};
