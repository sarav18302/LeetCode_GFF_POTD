class Solution {
public:
    int helper(vector<int>& prices, int idx, int buy, vector<vector<int>>& dp)
    {
        if(idx == prices.size())
        return 0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        int opt1 = 0, opt2 = 0;
        if(buy == 0)
        {
            opt1 = helper(prices,idx+1,buy,dp);
            opt2 = -prices[idx]+helper(prices,idx+1,1,dp);
        }
        else
        {
            opt1 = helper(prices,idx+1,buy,dp);
            opt2 = prices[idx]+helper(prices,idx+1,0,dp);
        }
        return dp[idx][buy] = max(opt1,opt2);
    } 
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,-1));
    //    return helper(prices, 0,0,dp) ;
    int n = prices.size();
    dp[n][0] = dp[n][1] = 0;
    long profit;
    for(int ind = prices.size()-1;ind>=0;ind--)
    {
        for(int buy = 1;buy>=0;buy--)
        {
            if (buy == 0) { // We can buy the stock
                profit = max(0 + dp[ind + 1][0], -prices[ind] + dp[ind + 1][1]);
            }

            if (buy == 1) { // We can sell the stock
                profit = max(0 + dp[ind + 1][1], prices[ind] + dp[ind + 1][0]);
            }

            dp[ind][buy] = profit;
        }
    }
    return dp[0][0];
    }
};