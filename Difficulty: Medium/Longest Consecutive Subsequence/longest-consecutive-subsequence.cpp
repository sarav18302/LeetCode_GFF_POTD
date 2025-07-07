class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        map<int,int>mp;
        int n = arr.size();
        for(int i =0;i<n;i++)
        {
            mp[arr[i]] = i;
        }
        int ans = 0;
        for(int i =0;i<n;i++)
        {
            int cnt = 1;
            int j = 1;
            while(mp.find(arr[i]+j)!=mp.end())
            {
                cnt++;
                j++;
            }
            ans = max(ans,cnt);
        }
        return ans;
    }
};