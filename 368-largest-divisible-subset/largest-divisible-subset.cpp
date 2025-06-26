class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1),hash(n);
        sort(nums.begin(),nums.end());
        for(int i =0;i<n;i++)
        {
            hash[i] = i;
            for(int prev=0;prev <=i-1;prev++)
            {
                if(nums[i]%nums[prev] == 0 &&  1+dp[prev] > dp[i] )
                {
                    dp[i] =  1+dp[prev];
                    hash[i] = prev;
                }
            }            
        }
     int maxi = -1;
    int ans = -1;
    for(int i =0;i<n;i++)
    {
        // cout<<nums[i]<<" "<<dp[i]<<" "<<hash[i]<<endl;
        if(dp[i]>ans)
        {
            ans = dp[i];
            maxi = i;
        }
    }

    vector<int> res;
    res.push_back(nums[maxi]);
    while(maxi != hash[maxi])
    {
        res.push_back(nums[hash[maxi]]);
        maxi = hash[maxi];
    }
            
    reverse(res.begin(),res.end());
    return res;
    }
};