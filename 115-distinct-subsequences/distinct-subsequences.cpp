class Solution {
public:
    int helper(string &s, string &t, int idx, string temp, int it, vector<vector<int>> &dp)
    {
        if(idx <0 || it <0)
        {
            reverse(temp.begin(),temp.end());
            if(temp == t)
            return 1;
            else
            return 0;
        }
        if(dp[idx][it] !=-1) return dp[idx][it];
        int take = 0;
        // cout<<s[idx]<< " "<<t[it]<<" "<<temp<<endl;
        if(s[idx] == t[it])
        {
            take = helper(s,t,idx-1,temp+s[idx],it-1,dp) ;
        }
        int ntk = helper(s,t,idx-1,temp,it,dp);
        // cout<<ntk + take<<endl;
        return dp[idx][it] = ntk + take;
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size(),vector<int>(t.size(),-1));
        return helper(s,t,s.size()-1,"",t.size()-1,dp);
    }
};