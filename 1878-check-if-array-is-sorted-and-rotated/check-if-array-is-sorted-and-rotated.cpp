class Solution {
public:
    bool check(vector<int>& nums) {

    int n = nums.size();
     for(int x =0 ;x<n;x++)
     {
        bool flag = true;
        for(int i =0;i<n-1;i++)
        {
            int idx = (i+x)%n, idx1 = (i+x+1)%n;
            if(nums[idx] > nums[idx1])
            {
                flag = false;
                break;
            }
        }
        if(flag)
        return true;
     }
     return false;   
    }
};