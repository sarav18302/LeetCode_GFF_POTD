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
        vector<vector<int>>dp(arr.size(),vector<int>(arr.size(),-1));
        return helper(arr,1,arr.size()-1,dp);
    }
};