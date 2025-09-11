class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
        int n = arr.size();
        int l =0, r =0, jumps = 0;
        if(arr[0] ==0 )
        return -1;
        while(r<n-1)
        {
            if(l>r)
            return -1;
            int farthest = 0;
            for(int i = l;i<=r;i++)
            {
                farthest = max(farthest,i+arr[i]);
            }
            l = r+1;
            r = farthest;
            jumps++;
        }
        return jumps;
    }
};
