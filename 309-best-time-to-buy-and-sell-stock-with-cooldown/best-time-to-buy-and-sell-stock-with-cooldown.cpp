class Solution {
public:
        int helper(vector<int>& prices, int idx, int buy, vector<vector<int>>& dp)
    {
        if(idx >= prices.size())
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
            opt2 = prices[idx]+helper(prices,idx+2,0,dp);
        }
        return dp[idx][buy] = max(opt1,opt2);
    } 
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
       return helper(prices, 0,0,dp) ;
    }
};