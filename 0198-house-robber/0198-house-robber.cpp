class Solution {
public:
    
    int helper(vector<int> nums, int i,vector<int>& memo)
    {
        if(i<0)
        {
            return 0;
        }
        if(memo[i]>=0)
        {
            return memo[i];
        }
        int res = max(helper(nums,i-2,memo)+nums[i],helper(nums,i-1,memo));
        memo[i] =res;
        return res;
    }
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(),-1);
        return helper(nums,nums.size()-1,memo);
    }
};