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
        vector<vector<int>>dp(cuts.size()+2,vector<int>(cuts.size()+2,0));
        // return helper(cuts,1,N,dp);
        // cout<<N<<endl;
        for(int i = N;i>=1;i--)
        {
            for(int j = i;j<=N;j++)
            {
                int mini = 1e9;
                for(int idx = i;idx<=j;idx++)
                {
                    // cout<<i<<" "<<j<<" "<<idx<<endl;
                    int  cost = (cuts[j+1] - cuts[i-1]) +dp[i][idx-1] + dp[idx+1][j];
                    mini = min(mini,cost);
                }
                dp[i][j] = mini;
            }
        }
    return dp[1][N];
    }
};