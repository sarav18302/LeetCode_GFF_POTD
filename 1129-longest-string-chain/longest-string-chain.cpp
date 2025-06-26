class Solution {
public:
     static bool compare(const string& a, const string& b) {
        return a.size() < b.size();          // ascending by length
    }
    bool valid(string a, string b)
    {
        int penality = 0;
        int n = a.size(), m = b.size();
        int i = 0,j=0;
        while(i<n && j<m )
        {
            if(a[i]!=b[j])
            {
                if(penality==0)
                penality++;
                else
                return false;
                j++;
            }
            else
            {
                i++;
                j++;
            }
        }
        return true;
    }
    int helper(vector<string>& words, int idx,int prev_idx,vector<vector<int>> &dp)
    {
        if(idx < 0)
        return 0;
        int take = 0;
        
        // if(prev_idx!=-1)
        // {
        //     if (words[idx].size()+1 == words[prev_idx].size())
        //     {
        //         cout<<words[idx]<<" " <<words[prev_idx]<<" ";
        //         cout<<valid(words[idx],words[prev_idx])<<endl;
        //     }
            
        // }
        if(dp[idx][prev_idx+1]!=-1) return dp[idx][prev_idx+1];
        if(prev_idx == -1 || (words[idx].size()+1 == words[prev_idx].size() && valid(words[idx],words[prev_idx])))
        take = 1+helper(words,idx-1,idx,dp);
        // cout<<words[idx].size()<<" "<<words[prev_idx].size()<<endl;
        int ntk = helper(words,idx-1,prev_idx,dp);
        return dp[idx][prev_idx+1] = max(ntk,take);
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),Solution::compare);
        // for(auto x: words)
        // cout<<x<<" ";
        // cout<<endl;
        vector<vector<int>> dp(words.size(),vector<int>(words.size()+1,-1));
        return helper(words,words.size()-1,-1,dp);
    }
};