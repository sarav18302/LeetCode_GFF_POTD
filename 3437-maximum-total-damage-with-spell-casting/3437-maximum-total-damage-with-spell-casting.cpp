class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        sort(power.begin(),power.end());
        int n = power.size();
        vector<long long>dp(n+1,0);
        long long max_dp = 0;
        for(int i =0, j = 0;i<n;i++)
        {
            if(power[i] == power[max(0,i-1)])
            {
                dp[i+1] = power[i]+dp[i];
            }
            else
            {
                while(power[j]+2<power[i])
                {
                    max_dp = max(dp[++j],max_dp);
                    
                }
                dp[i+1] = power[i] + max_dp;
            }
            
        }
        return *max_element(dp.begin(),dp.end());
    }
};