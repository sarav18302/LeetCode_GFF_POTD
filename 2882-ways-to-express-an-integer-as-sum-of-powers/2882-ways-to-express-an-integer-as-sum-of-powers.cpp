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
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        if(n>x)
        return helper(n,x,n/x,dp);
        else
        return helper(n,x,n,dp);
    }
};