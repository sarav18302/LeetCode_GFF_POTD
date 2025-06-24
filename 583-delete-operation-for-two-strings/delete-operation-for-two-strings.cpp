class Solution {
public:
    int minDistance(string text1, string text2) {
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
        return n+m -2*dp[m];
    }
};