class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i =0,j = 0;
        int s = 0;
        int ans = 0;
        for(i =0;i<n;i++)
        {
            if(nums[i] == 0)
            s++;
            while(s>k)
            {
                if(nums[j] == 0)
                {
                    s--;
                }
                j++;

            }
            ans = max(ans,i-j+1);
        }
        return ans;
    }
};