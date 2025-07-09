class Solution {
  public:
    bool helper(vector<int>& arr, int k, int idx, vector<vector<int>> &dp)
    {
        if(k ==0)
        return true;
        if(idx == arr.size() || k<0) return false;
        if(dp[idx][k] !=-1) return dp[idx][k];
        bool take = helper(arr,k-arr[idx],idx+1,dp);
        bool ntk = helper(arr,k,idx+1,dp);
        return dp[idx][k] = take || ntk;
    }
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        // Code here
        vector<vector<int>> dp(arr.size(),vector<int>(k+1,-1));
        return helper(arr,k,0,dp);
    }
};