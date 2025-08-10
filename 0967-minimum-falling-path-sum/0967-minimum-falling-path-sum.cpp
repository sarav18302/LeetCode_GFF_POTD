class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,1e9));
        dp[0][0] = matrix[0][0];
        for(int i =1;i<=n;i++)
        dp[0][i] = matrix[0][i-1];
        for(int i =1;i<n;i++)
        {
            for(int j = 1;j<=n;j++)
            {
                int mini = 1e9;
                if(j+1<=n)
                mini = dp[i-1][j+1];
                mini = min(mini,min(dp[i-1][j-1],dp[i-1][j]));
                dp[i][j] = matrix[i][j-1] + mini;
            }
        }
        int ans = 1e9;
        for(auto row: dp)
        {
            for(auto x: row)
            {
                cout<<x<<" ";
            }
            cout<<endl;
        }
        for(int i =0;i<=n;i++)
        ans = min(ans, dp[n-1][i]);
        return ans;
    }
};