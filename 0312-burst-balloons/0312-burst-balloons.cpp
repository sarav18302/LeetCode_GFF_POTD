class Solution {
public:
    int dp[301][301];
    int helper(vector<int>& nums,int i, int j )
    {
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int maxi = INT_MIN;
        for(int idx = i;idx<=j;idx++)
        {
            int cost = nums[i-1]*nums[idx]*nums[j+1] + helper(nums,i,idx-1)+helper(nums,idx+1,j);
            maxi = max(maxi,cost);
        }
        return dp[i][j] = maxi;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        return helper(nums,1,n);
    }
};