class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>>dp(m+1,vector<int>(m+1,1e9));
        for(int i =0;i<m;i++)
        dp[0][i] = triangle[0][0];

        for(int i =1;i<m;i++)
        {
            // cout<<i<<endl;
            // cout<<triangle[i][0]<<endl;
            for(int j =1;j<=triangle[i].size();j++)
            {
                // cout<<i<<" "<<j<<endl;
                dp[i][j] = triangle[i][j-1] + min(dp[i-1][j-1], dp[i-1][j]);
            }
        }
        int ans = 1e9;
        for(auto row: dp)
        {
            for(auto x: row)
            {
                cout<<x<<" ";
            }
            cout<<endl;
        }
        for(auto x:dp[m-1])
        {
            ans = min(ans,x);
        }
        return ans;
    }
};