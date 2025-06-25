class Solution {
public:
    bool helper(string &s, string &p, int i , int j, vector<vector<int>> &dp)
    {
        if(i<0 && j<0)
        return true;
        if(i<0 && j>=0)
        {
            for(int k =j ; k>=0;k--)
            {
                if(p[k]!= '*')
                return false;
            }
            return true;
        }
        if(j<0 && i>=0)
        return false;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i] == p[j] || p[j] == '?')
        return dp[i][j] = helper(s,p,i-1,j-1,dp);
        if(p[j] == '*')
        {
            return dp[i][j] = helper(s,p,i,j-1,dp) || helper(s,p,i-1,j,dp);
        }
        return dp[i][j] = false;
    }

    bool isAllStars(string &S1, int i) {
    // S1 is taken in 1-based indexing
    for (int j = 1; j <= i; j++) {
        if (S1[j - 1] != '*')
            return false;
    }
    return true;
}

    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size()+1,vector<bool>(p.size()+1,false));
        // return helper(s,p,s.size()-1,p.size()-1,dp);
        int n = s.size(), m = p.size();
        dp[0][0] = true;
        for(int i =1;i<=n;i++)
        {
            dp[i][0] = false;
        }
        for(int j = 1;j<=m;j++)
        {
            dp[0][j] = isAllStars(p,j);
        }
        for(int i =1;i<=n;i++)
        {
            for(int j =1;j<=m;j++)
            {
                if(s[i-1] == p[j-1] || p[j-1] == '?')
                dp[i][j] = dp[i-1][j-1];
                else if(p[j-1] == '*')
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
                else
                dp[i][j] = false;
            }
        }
        return dp[n][m];
    }
};