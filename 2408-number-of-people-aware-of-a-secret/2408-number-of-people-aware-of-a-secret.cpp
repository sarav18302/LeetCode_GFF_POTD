class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> dp(n+1);
        dp[0] = 0;
        int mod = 1e9+7;
        for(int i =1;i<=delay;i++)
        dp[i] = 1;
        for(int i = delay+1;i<=n;i++)
        {
            for(int j = delay;j<forget;j++)
            {
                if(i-j>=0)
                {
                    dp[i] = (dp[i]%mod +dp[i-j]%mod)%mod;
                }
            }
            dp[i]+=1;
            if(i-forget>=1) dp[i]--;
        }
        return dp[n];
    }
};