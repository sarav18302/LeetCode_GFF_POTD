class Solution {
  public:
    map<int,string> mp;
    
    void helper(vector<int> &arr,int idx, string curr, vector<string>&ans)
    {
        int n = arr.size();
        if(idx==n)
        {
            ans.push_back(curr);
            return ;
        }
        if(arr[idx] == 0 || arr[idx] == 1)
        helper(arr,idx+1,curr,ans);
        
        for(auto x: mp[arr[idx]])
        {
            helper(arr,idx+1,curr+x,ans);
        }
    }
    vector<string> possibleWords(vector<int> &arr) {
        // code here
        vector<string>ans;
        mp[0] = "";
        mp[1] = "";
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        helper(arr,0,"",ans);
        return ans;
        
    }
};