class Solution {
  public:
  int helper(vector<int> &arr,int i,int j, vector<vector<int>>&dp)
  {
      if(i==j)
      return 0;
      int mini = 1e9;
      if(dp[i][j]!=-1) return dp[i][j];
      for(int k = i;k<=j-1;k++)
      {
          int steps = arr[i-1]*arr[k]*arr[j] + helper(arr,i,k,dp) +helper(arr,k+1,j,dp);
          mini = min(mini,steps);
      }
      return dp[i][j] = mini;
  }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        vector<vector<int>>dp(arr.size()+1,vector<int>(arr.size()+1,0));
        // return helper(arr,1,arr.size()-1,dp);
        int n = arr.size();
        int ans = 1e9;
        for(int i = n-1;i>=1;i--)
        {
            for(int j = i+1;j<=n-1;j++)
            {
                int mini = 1e9;
                for(int k = i;k<= j-1;k++)
                {
                    int steps = arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];
                    mini = min(mini,steps);
                }
                dp[i][j] = mini;
                
            }
        }
        
        // for(auto x: dp)
        // {
        //     for(auto y: x)
        //     {
        //         cout<<y<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[1][n-1];
    }
};