class Solution {
public:
    void helper(vector<int>& nums, vector<int> temp,vector<vector<int>>&ans, int idx )
    {
        if(idx ==nums.size())
        {
            ans.push_back(temp);
            return ;
        }
        temp.push_back(nums[idx]);
        helper(nums,temp,ans,idx+1);
        temp.pop_back();
        helper(nums,temp,ans,idx+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(nums,{},ans,0);
        return ans;
    }
};