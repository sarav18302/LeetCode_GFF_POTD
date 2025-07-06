class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0,j=0;
        while(i<n && j<n)
        {
            cout<<nums[i]<<endl;
            if(nums[i]!=0)
            {
                i++;
                j = i+1;
            }
            else if(nums[i] == 0)
            {
                while(j<n && nums[j] == 0 )
                j++;
                if(j<n)
                {
                    swap(nums[i],nums[j]);
                    i++;
                }
                
            }
        }
    }
};