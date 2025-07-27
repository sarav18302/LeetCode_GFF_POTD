class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r=n-1;
        int ans = -1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(nums[mid] == target)
            {
                ans = mid;
                break;
            }
            else if(nums[mid] > target)
            {
                r = mid -1;
            }
            else
            {
                l = mid+1;
            }
        }
        if(ans == -1)
        return {-1,-1};
        else
        {
            vector<int>res;
            int first = ans;
            for(int i = ans; i>=0;i--)
            {
                if(nums[i]!= nums[ans])
                break;
                first = i;
            }
            int last = ans;
            for(int i =ans;i<n;i++)
            {
                if(nums[i]!= nums[ans])
                break;
                last = i;
            }
            return {first,last};
        }
    }
};