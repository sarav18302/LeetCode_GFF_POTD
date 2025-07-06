class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int ans = 0,cnt = 0;
        for(int i =0;i<n;i++)
        {
            if(nums[i]!=1)
            {
                ans = max(ans,cnt);
                cnt = 0;
            }
            else
            {
                cnt++;
                ans = max(ans,cnt);
            }
        }
        return ans;
    }
};