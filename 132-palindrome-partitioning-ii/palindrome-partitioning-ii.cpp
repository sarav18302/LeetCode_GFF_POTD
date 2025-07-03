class Solution {
public:
     bool isValid(string &s, int i ,int j)
     {
        while(i<=j)
        {
            if(s[i]!=s[j])
            return false;
            i++;
            j--;
        }
        return true;
     }
    int helper(string &s, int i,vector<int> &dp)
    {
        if(i==s.size()) return 0;
        int mini = 1e9;
        if(dp[i]!=-1) return dp[i];
        for(int j =i;j<s.size();j++)
        {
            if(isValid(s,i,j))
            {
                int take = 1 + helper(s,j+1,dp);
                mini = min(mini,take);
            }
        }
        return dp[i] = mini;
    }
    int minCut(string s) {
        vector<int> dp(s.size(),-1);
        return helper(s,0,dp) -1;
    }
};