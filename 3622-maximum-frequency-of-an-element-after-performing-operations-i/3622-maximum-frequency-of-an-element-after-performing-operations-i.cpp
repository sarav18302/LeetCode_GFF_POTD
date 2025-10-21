class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(),nums.end());
        map<int,int>mp;
        for(auto x: nums)
        mp[x]++;
        int n =  nums.size(), left = 0, right = 0,ans = 0;
        for(int mid = 0;mid<n;mid++)
        {
            while(nums[mid] - nums[left] > k)
            left++;
            while(right<n-1 && nums[right+1]-nums[mid]<=k)
            right++;
            int total = right-left+1;
            ans = max(ans, min(total - mp[nums[mid]],numOperations)+mp[nums[mid]]);
        }
        left = 0;
        for(right = 0;right <n ;right++)
        {
            int mid = (nums[left]+nums[right])/2;
            while(mid-nums[left]> k || nums[right]-mid >k )
            {
                left++;
                mid = (nums[left]+nums[right])/2;
            }
            ans = max(ans,min(right-left+1,numOperations));
        }
        return ans;
    }
};