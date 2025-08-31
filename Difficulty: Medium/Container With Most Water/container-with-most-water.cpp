class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n = arr.size();
        int l = 0, r= n-1;
        int ans = 0;
        while(l<r)
        {
            int water = min(arr[l],arr[r])*(r-l);
            ans = max(ans,water);
            if(arr[l]<arr[r])
            l++;
            else
            r--;
        }
        return ans;
    }
};