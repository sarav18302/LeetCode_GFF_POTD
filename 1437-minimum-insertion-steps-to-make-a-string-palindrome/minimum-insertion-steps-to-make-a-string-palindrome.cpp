class Solution {
public:
    int minInsertions(string s) {
        string rev = s;
        reverse(rev.begin(),rev.end());
        int n = s.size();
        vector<int> dp(s.size()+1,0), curr(rev.size()+1,0);
        for(int i =1;i<=n;i++)
        {
            for(int j = 1;j<=n;j++)
            {
                // if(text1[i-1]!=text2[j-1])
                // dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                // else
                // dp[i][j] = 1+ dp[i-1][j-1];
                if(s[i-1]!=rev[j-1])
                curr[j] = max(dp[j], curr[j-1]);
                else
                curr[j] = 1+ dp[j-1];
            }
            dp= curr;
        }
        int lcs =  dp[n];
        return n-lcs;
    }
};