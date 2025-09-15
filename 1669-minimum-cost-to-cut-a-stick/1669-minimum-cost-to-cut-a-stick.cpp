class Solution {
public:
    int helper(vector<int>& cuts, int i, int j,vector<vector<int>>&dp)
    {
        if(i > j)
        return 0;
        int mini = 1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int k = i;k<=j;k++)
        {
            int steps = abs(cuts[j+1]-cuts[i-1]) + helper(cuts,i,k-1,dp)+helper(cuts,k+1,j,dp);
            mini = min(mini,steps);
        }
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        int N = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        vector<vector<int>>dp(cuts.size()+1,vector<int>(cuts.size()+1,-1));
        return helper(cuts,1,N,dp);
    }
};