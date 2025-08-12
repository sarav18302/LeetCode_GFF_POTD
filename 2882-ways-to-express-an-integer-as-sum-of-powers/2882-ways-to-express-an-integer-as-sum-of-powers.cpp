class Solution {
public:
    int mod = 1e9+7;
    int helper(int n,int x,int idx, vector<vector<int>>&dp)
    {
        if(n == 0)
        return 1;
        if(idx==0 || n<0)
        return 0;
        if(dp[n][idx]!=-1) return dp[n][idx];
        int take = helper(n-pow(idx,x),x,idx-1,dp);
        int ntk = helper(n,x,idx-1,dp);
        return dp[n][idx] = (take+ntk)%mod;
    }
    int numberOfWays(int n, int x) {
        
        // if(n>x)
        // return helper(n,x,n/x,dp);
        // else
        // return helper(n,x,n,dp);
        int max_idx = 0;
        if(n>x)
        max_idx = n/x;
        else
        max_idx = n;
        vector<vector<int>>dp(n+1,vector<int>(max_idx+1,0));
        for(int i =0;i<=max_idx;i++)
        dp[0][i] = 1;
        for(int i =1;i<=n;i++)
        {
            for(int idx = 1;idx<=max_idx;idx++)
            {
                long long val = pow(idx,x);
                long long take = 0;
                if(val <= i)
                take = dp[i-val][idx-1];
                long long ntk = dp[i][idx-1];
                dp[i][idx] = (take+ntk)%mod;
            }
        }
        return dp[n][max_idx];
    }
};