class Solution {
public:
     int helper(int idx,vector<int>&dp)
    {
        if(idx == 0)
        return 1;
        if(idx <0)
        return 0;
        if(dp[idx]!=-1) return dp[idx];
        return dp[idx] = helper(idx-1,dp)+ helper(idx-2,dp);
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        helper(n,dp);
        return dp[n];
        // vector<int>dp(n+1,0);
        // dp[0] = 1;
        // for(int i =1;i<=n;i++)
        // {
        //     if(i-1>=0)
        //     dp[i] = dp[i-1];
        //     if(i-2>=0)
        //     dp[i]+=dp[i-2];
        // }
        // return dp[n];
    }

};