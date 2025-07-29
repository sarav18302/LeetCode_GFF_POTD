class Solution {
public:
    int findMax(vector<int>& nums)
    {
        int maxi = nums[0];
        for(auto x: nums)
        maxi = max(maxi,x);
        return maxi;
    }
    int findDivSum(vector<int>& nums, int val)
    {
        int ans = 0;
        for(auto x:nums)
        {
            ans += (x/val);
            if(x%val)
            ans+=1;
        }
        return ans;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1, r= findMax(nums);
        int ans = -1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            int val = findDivSum(nums,mid);
            // cout<<mid<<" "<<val<<endl;
            if(val<=threshold)
            {
                ans = mid;
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        return ans;
    }
};