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
        vector<vector<long long>> dp(s.size()+1,vector<long long>(t.size()+1,0));
        // return helper(s,t,s.size()-1,"",t.size()-1,dp);
        static int MOD = (int)1e9 + 7;    
        int n = s.size(), m = t.size();
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=1;
        }
        for(int i=1;i<=m;i++)
        {
            dp[0][i]=0;
        }
        for(int i =1;i<=n;i++)
        {
            for(int j =1;j<=m;j++)
            {
                long long take = 0;
                if(s[i-1]==t[j-1])
                {
                    take = dp[i-1][j-1];
                }
                long long ntk = dp[i-1][j];
                dp[i][j]= (take+ntk) % MOD;
            }
        }
        return (int)dp[n][m];
    }
};