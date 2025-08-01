class Solution {
public:
    bool search(vector<int>& nums, int target) {
         int n = nums.size();
        int l = 0, r= n-1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(nums[mid] == target)
            {
                return true;
            }
            else if(nums[l] == nums[mid] && nums[mid] == nums[r])
            {
                l++;
                r--;
            }
            else if(nums[l] <= nums[mid])
            {
                if(nums[l] <= target && nums[mid] >= target)
                {
                    r = mid-1;
                }
                else
                {
                    l = mid+1;
                }
            }
            else
            {
                if(nums[mid] <= target && nums[r] >= target)
                {
                    l = mid+1;
                }
                else
                {
                    r = mid-1;
                }
            }
        }
        return false;
    }
};