class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int>dp(n,0);
        int ans = INT_MIN;
        for(int i = n-1;(n-1-i)<k;i--)
        {
            dp[i] = energy[i];
            ans = max(dp[i],ans);
        }
        for(int i = n-k-1;i>=0;i--)
        {
            dp[i] = dp[i+k]+energy[i];
             ans = max(dp[i],ans);
        }
        return ans;
    }
};