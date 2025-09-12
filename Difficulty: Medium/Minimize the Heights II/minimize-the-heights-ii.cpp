class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        sort(arr.begin(),arr.end());
        int n = arr.size();
        int minH = arr[0]+k, maxH = arr[n-1]-k;
        int res = arr[n-1]-arr[0];
        for(int i =1;i<n;i++)
        {   
            if(arr[i] -k <0)
            continue;
            minH = min(arr[0]+k,arr[i]-k);
            maxH = max(arr[n-1]-k,arr[i-1]+k);
            if(minH>=0)
            res = min(res,maxH-minH);
        }
        return res;
        
    }
};