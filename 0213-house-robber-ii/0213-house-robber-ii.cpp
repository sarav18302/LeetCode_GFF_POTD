class Solution {
public:
    int helper(vector<int>& nums,int start,int end )
    {
        vector<int>dp(end-start+2,0);
        for(int i = 1;i<=(end-start+1);i++)
        {
            dp[i] = dp[i-1];
            if(i-2>=0)
            dp[i] = max(dp[i],dp[i-2]+nums[start+i-1]);
            else
            dp[i] = max(dp[i],nums[start+i-1]);
        }
        return dp[end-start+1];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
        return nums[0];
        // cout<<helper(nums,0,n-2)<<" "<<helper(nums,1,n-1);
        return max(helper(nums,0,n-2),helper(nums,1,n-1));
    }
};