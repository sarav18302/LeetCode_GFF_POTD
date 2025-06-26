
class Solution {
  public:
    int LongestBitonicSequence(int n, vector<int> &nums) {
        // code here
        vector<int> dpf(n,0), dpb(n,0);
        for(int idx =0;idx<n;idx++)
        {
            for(int prev = 0;prev <=idx-1;prev++)
            {
                if(nums[idx] > nums[prev] && dpf[idx] < 1+dpf[prev] )
                dpf[idx] = 1+dpf[prev];
            }
        }
        for(int idx =n-1;idx>=0;idx--)
        {
            for(int prev = idx+1;prev <n;prev++)
            {
                if(nums[idx] > nums[prev] && dpb[idx] < 1+dpb[prev] )
                dpb[idx] = 1+dpb[prev];
            }
        }
        int ans = 0;
        for(int i =0;i<n;i++)
        {
            if(dpf[i]>0 && dpb[i] > 0)
            ans = max(ans,dpf[i]+dpb[i]);
        }
        return ans >0 ? ans+1:0;
    }
};
