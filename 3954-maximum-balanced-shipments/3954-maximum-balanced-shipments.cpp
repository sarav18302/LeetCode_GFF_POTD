class Solution {
public:
    int maxBalancedShipments(vector<int>& nums) {
        int maxele = nums[0];
        int n = nums.size(),cnt =0;
        for(int i =1;i<n;i++)
        {
            if(maxele > nums[i])
            {
                cnt++;
                if(i+1<n)
                {
                    i+=1;
                    maxele = nums[i];
                }
            }
            else
            {
                maxele = nums[i];
            }
        }
        return cnt;
    }
};