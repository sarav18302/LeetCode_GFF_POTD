class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int max_val = *max_element(nums.begin(),nums.end());
        int k = static_cast<int>(floor(log2(max_val)))+1;
        int mask = 1<<k;
        vector<int>dp(mask,0);
        for(int x:nums)
        dp[x] = x;

        for(int j =0;j<k;j++)
        {
            for(int i =0;i<mask;i++)
            {
                if(i & (1<<j))
                dp[i] = max(dp[i], dp[i^(1<<j)]);
            }
        }
        long long res = 0;
        for(int x:nums)
        {
            int complement = (mask-1)^x;
            res = max(res,1LL*x*dp[complement]);
        }
        return res;
    }
};