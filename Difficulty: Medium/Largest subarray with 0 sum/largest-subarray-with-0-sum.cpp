class Solution {
  public:
    int maxLength(vector<int>& arr) {
        // code here
        int n = arr.size(), ans = 0;
        int sum = 0;
        map<int,int>mp;
        for(int i =0;i<n;i++)
        {
            sum += arr[i];
            if(sum == 0)
            {
                ans = i+1;
            }
            else if(mp.find(sum)!=mp.end())
            {
                ans = max(ans, i- mp[sum]);
            }
            else
            mp[sum] = i;
                
        }
        return ans;
    }
};