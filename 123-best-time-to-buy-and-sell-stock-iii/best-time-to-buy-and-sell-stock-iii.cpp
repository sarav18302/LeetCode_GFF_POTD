class Solution {
public:
    int helper(vector<int>& prices, int idx, int buy, int time, vector<vector<vector<int>>>& dp)
    {
        if(idx == prices.size() || time == 2)
        return 0;
        if(dp[idx][buy][time]!=-1) return dp[idx][buy][time];
        int opt1 = 0, opt2 = 0;
        if(buy == 0)
        {
            opt1 = helper(prices,idx+1,buy,time,dp);
            if(time<2)
            opt2 = -prices[idx]+helper(prices,idx+1,1,time,dp);
        }
        else
        {
            opt1 = helper(prices,idx+1,buy,time,dp);
            if(time<2)
            {
                opt2 = prices[idx]+helper(prices,idx+1,0,time+1,dp);
            }
            
        }
        return dp[idx][buy][time] = max(opt1,opt2);
    } 
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>>(2+1,vector<int>(2+1,0)));
        // return helper(prices,0,0,0,dp);
        int n = prices.size();
        for(int i = n-1; i>=0;i--)
        {
            for(int j = 0;j<=1;j++)
            {
                for(int k =0;k<=1;k++)
                {
                    int opt1 = 0,opt2 = 0;
                    if(j ==0)
                    {
                        opt1 = dp[i+1][0][k];
                        opt2 = -prices[i] +dp[i+1][1][k];
                    }
                    else
                    {
                        opt1 = dp[i+1][1][k];
                        opt2 = prices[i] +dp[i+1][0][k+1];
                    }
                    dp[i][j][k] = max(opt1,opt2);
                }
            }
        }
        return dp[0][0][0];
    }
};