class Solution {
public:
    int helper(vector<int>& coins,int amount, int idx,vector<vector<int>>&dp)
    {
        if(amount == 0)
        return 1;
        if(idx == 0)
        {
            if(amount% coins[idx] == 0)
            return 1;
            else
            {
                return 0;
            }
        }
        if(dp[idx][amount]!=-1) return dp[idx][amount];
        int take = 0;
        if(amount>=coins[idx])
        take = helper(coins,amount-coins[idx],idx,dp);
        int ntk = helper(coins,amount,idx-1,dp);
        return dp[idx][amount] = take + ntk;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        return helper(coins,amount,coins.size()-1,dp);
    }
};