class Solution {
  public:
    void helper(int n,int k,vector<int> curr, vector<vector<int>>& ans,int idx)
    {
        if(curr.size() == k)
        {
            if(n == 0)
            ans.push_back(curr);
            return ;
        }
        if(idx >9 || n<0)
        return ;
        curr.push_back(idx);
        helper(n-idx,k,curr,ans,idx+1);
        curr.pop_back();
        helper(n,k,curr,ans,idx+1);
        
    }
    vector<vector<int>> combinationSum(int n, int k) {
        // code here
        vector<vector<int>> ans;
        helper(n,k,{},ans,1);
        return ans;
    }
};