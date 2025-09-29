class Solution {
public:
    
    int helper(vector<int>& values,int i,int j,vector<vector<int>>&dp)
    {
        if(i+1==j)
        return 0;
        if(dp[i][j] != -1) return dp[i][j] ;
        long long  sum = 1e9;
        for(int k = i+1;k<j;k++)
        {
            cout<<i<<" "<<k<<" "<<j<<endl;
            long long cost = values[i]*values[k]*values[j] + helper(values,i,k,dp)+helper(values,k,j,dp);
            sum = min(sum,cost);
        }
        return dp[i][j] = sum;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        // vector<vector<int>>dp(n,vector<int>(n,-1));
        // return helper(values,0,n-1,dp);
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i =n-1;i>=0;i--)
        {
            for(int j = i+1;j<n;j++)
            {
                long long sum = 1e9;
                for(int k = i+1;k<j;k++)
                {
                    long long cost = values[i]*values[k]*values[j] + helper(values,i,k,dp)+helper(values,k,j,dp);
                    sum = min(sum,cost);
                }
                dp[i][j] = sum;
            }
        }
    return dp[0][n-1];
    }
};