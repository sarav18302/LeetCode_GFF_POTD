class Solution {
  public:
    void helper(vector<int>& arr, vector<int>vis, vector<vector<int>>&ans,vector<int>cur)
    {
        if(cur.size() == arr.size())
        {
            ans.push_back(cur);
            return ;
        }
        int n = arr.size();
        for(int i =0;i<n;i++)
        {
            if(vis[i]) continue;
            if(i-1>=0 && arr[i] == arr[i-1] && !vis[i-1]) continue;
            vis[i] = 1;
            cur.push_back(arr[i]);
            helper(arr,vis,ans,cur);
            cur.pop_back();
            vis[i] = 0;
        }
    }
    vector<vector<int>> uniquePerms(vector<int>& arr) {
        // code here
        sort(arr.begin(),arr.end());
        vector<vector<int>>ans;
        vector<int>vis(arr.size(),0);
        helper(arr,vis,ans,{});
        return ans;
        
    }
};