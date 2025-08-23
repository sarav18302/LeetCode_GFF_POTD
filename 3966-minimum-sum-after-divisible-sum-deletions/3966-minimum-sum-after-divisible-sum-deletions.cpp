class Solution {
public:
    long long minArraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long>dp(n+1,0);
        unordered_map<int,int> indexMap{{0,n}};
        int sum = 0;
        for(int i =n-1;i>=0;i--)
        {
            sum = (sum+nums[i])%k;
            dp[i] = nums[i]+dp[i+1];
            if(indexMap.count(sum))
            dp[i] = min(dp[i],dp[indexMap[sum]]);
            indexMap[sum] = i;
        }
    return dp[0];
    }
};