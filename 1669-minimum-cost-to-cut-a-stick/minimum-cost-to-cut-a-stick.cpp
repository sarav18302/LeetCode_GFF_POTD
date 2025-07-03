class Solution {
public:
    int helper(vector<int>& cuts, int i ,int j, vector<vector<int>>&dp)
    {
        if(i>j)
        return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini = 1e9;
        for(int idx = i;idx<=j;idx++)
        {
            int cost = (cuts[j+1] - cuts[i-1]) + helper(cuts,i,idx-1,dp) + helper(cuts,idx+1,j,dp);
            mini = min(mini,cost);
        }
        return dp[i][j] =  mini;
    }
    int minCost(int n, vector<int>& cuts) {
        int N = cuts.size();
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(cuts.size(),vector<int>(cuts.size(),-1));
        return helper(cuts,1,N,dp);
    }
};