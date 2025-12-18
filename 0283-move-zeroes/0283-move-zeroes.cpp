class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nums_length = nums.size();
        int curr = 0, itr = 0;
        while(curr < nums_length)
        {
            if(nums[curr] == 0)
            {
                curr++;
            }
            else
            {
                swap(nums[curr],nums[itr]);
                itr++;
                curr++;
                
            }
        }

    }
};

// [0] nums_length = 5 
// curr = 5, itr = 2