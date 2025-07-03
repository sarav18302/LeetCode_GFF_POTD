class Solution {
public:
    int helper(vector<int>& arr, int k, int i, vector<int> &dp)
    {
         int n = arr.size();
        if(i == n) return 0;
        if(dp[i]!=-1) return dp[i];
        int maxele = -1e9, maxi = -1e9,len =0;
        for(int idx = i;idx< min(i+k,n);idx++)
        {
            len++;
            maxele = max(maxele,arr[idx]);
            int cost = maxele*(len) + helper(arr,k,idx+1,dp);
            maxi = max(cost,maxi);
        }
        return dp[i] = maxi;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(),-1);
        return helper(arr,k,0,dp);
    }
};