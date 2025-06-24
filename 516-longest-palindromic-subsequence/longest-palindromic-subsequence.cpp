class Solution {
public:
    int helper(string &text1, int idx1, int idx2, vector<vector<int>> &dp)
    {
        if(idx1>idx2)
        return 0;
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        if(text1[idx1]!=text1[idx2])
        {
            return  dp[idx1][idx2] = max(helper(text1,idx1+1,idx2,dp),helper(text1,idx1,idx2-1,dp));
        }
        else
        {
            if(idx1!=idx2)
            return  dp[idx1][idx2] = 2+ helper(text1,idx1+1,idx2-1,dp);
            else
            return  dp[idx1][idx2] = 1+ helper(text1,idx1+1,idx2-1,dp);
        }
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp (s.size(),vector<int>(s.size(),-1));
        return helper(s,0,s.size()-1,dp);
        
    }
};