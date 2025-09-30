class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        for(int i = 1;i<n;i++)
        {
            vector<int>temp;
            for(int j =0;j<n-i;j++)
            {
                temp.push_back((nums[j]+nums[j+1])%10);
            }
            nums = temp;
        }
        return nums[0];
    }
};