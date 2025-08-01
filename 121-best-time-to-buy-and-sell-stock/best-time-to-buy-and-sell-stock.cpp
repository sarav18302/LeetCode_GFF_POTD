class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int minval = prices[0];  
        for(int i =1;i<prices.size();i++)
        {
            ans= max(ans, prices[i] - minval);
            minval = min(minval,prices[i]);
        }
        return ans;
    }
};
