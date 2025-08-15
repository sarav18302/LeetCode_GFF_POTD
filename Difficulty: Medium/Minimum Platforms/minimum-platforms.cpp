class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        int res = 0;
        int n = arr.size();
        int i =0,j=0;
        int cnt = 0;
        while(i<n && j<n)
        {
            if(arr[i] <= dep[j])
            {
                cnt+=1;
                i++;
            }
            else
            {
                cnt-=1;
                j++;
            }
            if(cnt>res)
            res = cnt;
        }
        return res;
    }
};
