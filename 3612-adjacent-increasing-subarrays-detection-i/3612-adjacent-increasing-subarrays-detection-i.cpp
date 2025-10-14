class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int inc = 1, prevInc = 0, maxlen = 0;
        for(int i =1 ;i<n;i++)
        {
            if(nums[i]>nums[i-1])
            inc++;
            else
            {
                prevInc = inc;
                inc = 1;
            }
            maxlen = max(maxlen,max(inc>>1,min(prevInc,inc)));
            if(maxlen >= k) return true;
        }
        return false;
    }
};