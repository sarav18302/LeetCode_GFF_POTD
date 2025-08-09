class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int i =0;
        bool left = false, center = false, right = false;
        for(;i<n-1;i++)
        {
            if(nums[i] >= nums[i+1])
            break;
            left = true;
        }
        for(;i<n-1;i++)
        {
            if(nums[i] <= nums[i+1])
            break;
            center = true;
        }

        for(;i<n-1;i++)
        {
            if(nums[i] >= nums[i+1])
            return false;
            right = true;
        }
        return left && center && right && i==n-1;
    }
};