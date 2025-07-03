class Solution {
public:
    int helper(vector<int>& nums, int i ,int j,vector<vector<int>> &dp)
    {
        if(i>j) return 0;
        if(dp[i][j]!= -1) return dp[i][j];
        int maxi = -1e9;
        for(int idx = i;idx<=j;idx++)
        {
            int cost = nums[i-1]*nums[idx]*nums[j+1] + helper(nums,i,idx-1,dp) +helper(nums,idx+1,j,dp);
            maxi = max(maxi,cost);
        }
        return dp[i][j] = maxi;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,0));
        // return helper(nums,1,n,dp);
        for(int i = n;i>=1;i--)
        {
            for(int j = i;j<=n;j++)
            {
                int maxi = -1e9;
                for(int idx = i;idx<=j;idx++)
                {
                    int cost = nums[i-1]*nums[idx]*nums[j+1] + dp[i][idx-1] +dp[idx+1][j];
                    maxi = max(maxi,cost);
                }
                dp[i][j] = maxi;
            }
        }
        return dp[1][n];
    }
};