class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 1, ele = nums[0];
        for(int i =1;i<nums.size();i++)
        {
            if(nums[i] != ele)
            {
                cnt --;
                if(!cnt)
                {
                    cnt = 1;
                    ele = nums[i];
                }
            }
            else
            {
                cnt++;
            }
        }
        return ele;
    }
};