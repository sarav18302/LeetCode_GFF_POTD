class Solution {
public:
      int helper(vector<int>& prices, int idx, int buy, int time, vector<vector<vector<int>>>& dp,int k)
    {
        if(idx == prices.size() || time == k)
        return 0;
        if(dp[idx][buy][time]!=-1) return dp[idx][buy][time];
        int opt1 = 0, opt2 = 0;
        if(buy == 0)
        {
            opt1 = helper(prices,idx+1,buy,time,dp,k);
            if(time<k)
            opt2 = -prices[idx]+helper(prices,idx+1,1,time,dp,k);
        }
        else
        {
            opt1 = helper(prices,idx+1,buy,time,dp,k);
            if(time<k)
            {
                opt2 = prices[idx]+helper(prices,idx+1,0,time+1,dp,k);
            }
            
        }
        return dp[idx][buy][time] = max(opt1,opt2);
    } 
    int maxProfit(int k, vector<int>& prices) {
         vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(k,-1)));
        return helper(prices,0,0,0,dp,k);
        
    }
};