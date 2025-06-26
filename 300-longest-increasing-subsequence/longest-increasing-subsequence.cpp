class Solution {
public:
    int helper(vector<int>& nums, int idx, int prev, vector<vector<int>> &dp)
    {
        if(idx<0)
        return 0;
        if(dp[idx][prev+1]!=-1) return dp[idx][prev+1];
        int take = 0;
        if(prev == -1 || nums[idx]<nums[prev])
        take = 1+helper(nums,idx-1,idx,dp);
        int ntk = helper(nums,idx-1,prev,dp);
        return dp[idx][prev+1] = max(take,ntk);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size()+1,-1));
        return helper(nums,nums.size()-1,-1,dp);
    }
};