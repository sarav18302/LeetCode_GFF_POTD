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
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),-1));
        return helper(nums,1,n,dp);
    }
};