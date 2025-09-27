class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,0);
        for(int i =1;i<=n;i++)
        {
           dp[i] = dp[i-1];
           if(i-2>=0)
           dp[i] = max(dp[i],dp[i-2]+nums[i-1]);
           else
           dp[i] = max(dp[i],nums[i-1]);
        }
        return dp[n];
    }
    // 0 1 2 4 3
};