class Solution {
public:
    int helper(string &text1, string &text2, int idx1, int idx2,vector<vector<int>> &dp)
    {
        if(idx1<0 || idx2< 0)
        return 0;
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        if(text1[idx1]!=text2[idx2])
        {
            return dp[idx1][idx2] =  max(helper(text1,text2,idx1-1,idx2,dp),helper(text1,text2,idx1,idx2-1,dp));
        }
        else
        {
            return dp[idx1][idx2] = 1+ helper(text1,text2,idx1-1,idx2-1,dp);
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        // vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,0));
        // return helper(text1,text2,text1.size()-1,text2.size()-1,dp);
        int n = text1.size(), m = text2.size();
        vector<int> dp(text2.size()+1,0), curr(text2.size()+1,0);
        for(int i =1;i<=n;i++)
        {
            for(int j = 1;j<=m;j++)
            {
                // if(text1[i-1]!=text2[j-1])
                // dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                // else
                // dp[i][j] = 1+ dp[i-1][j-1];
                if(text1[i-1]!=text2[j-1])
                curr[j] = max(dp[j], curr[j-1]);
                else
                curr[j] = 1+ dp[j-1];
            }
            dp= curr;
        }
        return dp[m];
    }
};