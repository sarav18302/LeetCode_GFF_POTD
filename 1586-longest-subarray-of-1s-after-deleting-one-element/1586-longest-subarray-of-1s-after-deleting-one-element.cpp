class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int low = 0, high =0,cnt =0,ans =0;
        int n = nums.size();
        while(high<n)
        {
            if(nums[high] == 0)
            {
                cnt++;
                while(cnt>1)
                {
                    // cout<<low<<endl;
                    if(nums[low] == 0)
                    {
                        cnt--;
                    }
                    low++;
                }
            }
            ans = max(ans,(high-low));
            high++;
        }
        return ans;
    }
};