class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // two pointer approach
        // 1st ptr points to the curr element (while traversing)
        //2nd ptr points to the position the unique element must be placed

        int nums_length = nums.size();
        int curr = 0, itr = -1;
        while(curr < nums_length)
        {
            
            swap(nums[curr++],nums[++itr]);
            while(curr <nums_length && nums[curr] == nums[itr])
            curr++;
            
        }
        return itr+1; 
    }
};

