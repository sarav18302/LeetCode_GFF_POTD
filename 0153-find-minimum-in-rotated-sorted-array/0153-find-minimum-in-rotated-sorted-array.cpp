class Solution {
public:
    int findMin(vector<int>& nums) {
        int x = -1e9;
        int n = nums.size();
        int  l =0, r= n-1;
        int ans = nums[0];
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(nums[l] <= nums[mid])
            {
               ans = min(nums[l],ans);
               l = mid+1;
            }
            else
            {
                ans = min(nums[mid],ans);
               r= mid-1;
            }
        }
        return ans;
    }
};