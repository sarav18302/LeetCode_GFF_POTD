class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,1e9));
        for(int i = 0;i<n;i++)
        {
            dp[0][i] = triangle[0][0];
        }
        for(int i = 1;i<n;i++)
        {
            for(int j = 1;j<=triangle[i].size();j++)
            {
                dp[i][j] = triangle[i][j-1] + min(dp[i-1][j-1],dp[i-1][j]);
            }
        }
        int ans = 1e9;
        for(int i = 0;i<=n;i++)
        {
            ans = min(ans,dp[n-1][i]);
        }
        return ans;
    }
};