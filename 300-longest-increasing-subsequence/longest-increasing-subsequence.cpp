class Solution {
public:
    int helper(vector<int>& nums, int idx, int prev, vector<vector<int>> &dp)
    {
        if(idx<0  )
        return 0;
        if(dp[idx][prev]!=-1) return dp[idx][prev];
        int take = 0;
        if(nums[idx]<nums[prev])
        take = 1+helper(nums,idx-1,idx,dp);
        int ntk = helper(nums,idx-1,prev,dp);
        return dp[idx][prev] = max(take,ntk);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),-1));
        int ans = 0;
        for(int i=nums.size()-1;i>=0;i--)
        {
            ans = max(ans,1+helper(nums,i-1,i,dp));
        }
        return ans;
    }
};