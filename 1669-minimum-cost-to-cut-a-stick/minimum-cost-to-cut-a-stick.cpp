class Solution {
public:
    int helper(vector<int>& cuts, int i ,int j,vector<vector<int>> &dp)
    {
        if(i>j)
        return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini = INT_MAX;
        for(int ind = i;ind<=j;ind++ )
        {
            // cout<<i<<" "<<j<<endl;
            int ans = cuts[j+1] - cuts[i-1] + helper(cuts,i,ind-1,dp)+ helper(cuts,ind+1, j,dp);
            mini = min(mini,ans);
        }
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        int N = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(N+2,vector<int>(N+2,0));
        // return helper(cuts,1,N,dp);
        for(int i =N;i>=1;i--)
        {
            // cout<<"Here"<<endl;
            for(int j = 1;j<=N;j++)
            {
                if (i > j) continue;
                int mini = INT_MAX;
                for(int ind = i;ind<=j;ind++ )
                {
                    int ans = cuts[j+1] - cuts[i-1] + dp[i][ind-1]+ dp[ind+1][j];
                    mini = min(mini,ans);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][N];
    }
};