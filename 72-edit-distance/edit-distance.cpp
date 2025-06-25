class Solution {
public:
    int helper(string &word1, string &word2, int i , int j, vector<vector<int>> &dp )
    {
        if(i<0 ) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!= -1) return dp[i][j];
        if(word1[i] == word2[j])
        return dp[i][j] = helper(word1,word2,i-1,j-1,dp);
        int del = 1+ helper(word1,word2,i-1,j,dp);
        int insert = 1+ helper(word1,word2,i,j-1,dp);
        int rep = 1+ helper(word1,word2,i-1,j-1,dp);
        return dp[i][j] = min(del,min(insert,rep));
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp (word1.size()+1,vector<int>(word2.size()+1,0));
        // return helper(word1,word2, word1.size()-1,word2.size()-1,dp);
        int n = word1.size(), m = word2.size();
        for(int i=0;i<=n;i++)
        dp[i][0] = i;
        for(int j =0;j<=m;j++)
        dp[0][j] = j;
        for(int i =1;i<=n;i++)
        {
            for(int j = 1;j<=m;j++)
            {
                if(word1[i-1]== word2[j-1])
                dp[i][j] = dp[i-1][j-1];
                else
                {
                    int del = 1+dp[i-1][j];
                    int ins = 1+dp[i][j-1];
                    int rep = 1+dp[i-1][j-1];
                    dp[i][j] =  min(del,min(ins,rep));
                }
                cout<<dp[i][j]<< " ";
            }
            cout<<endl;
        }
        return dp[n][m];
    }
};