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
        long long modulo=1e10+7;
        vector<vector<long long >>dp(coins.size()+2,vector<long long >(amount+2,-1));
        // return helper(coins,amount,coins.size()-1,dp);
        int n = coins.size();
        if(amount == 0) {
            return 1;
        }
        if(n==0)
          return 0;
        for(int i =0;i<=n;i++)
        dp[i][0] = 1;
        for(int i =0;i<=amount;i++)
        {
            dp[0][i] = 0;
        }
        for(int i =1;i<=coins.size();i++)
        {
            for(int j =1;j<=amount;j++)
            {
                long long  take = 0;
                if(coins[i-1]<=j)
                take = dp[i][j-coins[i-1]];
                long long  ntk = dp[i-1][j];
                dp[i][j] = (take + ntk)%modulo;
            }
        }

    return dp[coins.size()][amount];
    }
};