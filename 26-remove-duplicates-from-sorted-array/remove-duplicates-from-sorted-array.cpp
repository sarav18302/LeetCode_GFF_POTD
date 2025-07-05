class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
        return 1;
        int i = 0, j =1;
        int cnt = 1;
        while(i<n && j<n)
        {
            if(nums[i] == nums[j])
            {
                while(j<n && nums[i] == nums[j])
                {
                    j++;
                }

            }
            else
            {
                cnt++;
                int temp = nums[j];
                while(j<n && nums[i] == nums[j])
                {
                    j++;
                }
                nums[i+1] = temp;
                i++;
            }
        }
        cout<<cnt;
        return cnt;
    }
};