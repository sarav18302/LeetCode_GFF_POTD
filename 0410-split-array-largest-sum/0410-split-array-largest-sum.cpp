class Solution {
public:
    int findSplits(vector<int>& nums,int val)
    {
        int sum = 0, cnt = 1;
        for(int i =0;i<nums.size();i++)
        {
            if(sum+nums[i] <= val )
            {
                sum+=nums[i];
            }
            else
            {
                cnt++;
                sum = nums[i];
            }
        }
        return cnt;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int l = *max_element(nums.begin(),nums.end());
        int r = accumulate(nums.begin(),nums.end(),0);
        int ans = -1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            int val = findSplits(nums,mid);
            if(val>k)
            {
                l = mid+1;
            }
            else
            {
                ans = mid;
                r = mid-1;
            }
        }
    return ans;
    }
};