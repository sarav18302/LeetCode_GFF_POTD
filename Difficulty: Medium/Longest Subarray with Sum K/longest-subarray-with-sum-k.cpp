class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        map<int,int> prefix;
        int sum =0;
        int ans = 0;
        for(int i =0;i<n; i++)
        {
            sum+=arr[i];
            if(sum == k)
            {
                ans = max(ans, i+1);
            }
            int rem = sum -k;
            if(prefix.find(rem) != prefix.end())
            {
                ans = max(ans, i - prefix[rem]);
            }
            if(prefix.find(sum) == prefix.end())
            {
                prefix[sum] = i; 
            }
        }
        return ans;
    }
};