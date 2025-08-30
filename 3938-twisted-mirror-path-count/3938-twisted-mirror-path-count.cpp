class Solution {
public:
    int mod = 1e9+7;
    int helper(vector<vector<int>>& grid, int i, int j,int dir,vector<vector<vector<int>>>&dp)
    {
        int m = grid.size(), n = grid[0].size();
        if(i<0 || j<0 || i>=m || j>=n)
           return 0;
        // cout<<i<<" "<<j<<" "<<dir<<endl;
        if(i == m-1 && j ==n-1)
           {
            // cout<<"Here"<<endl;
                return 1;
           }
        if(dir!=-1 && dp[i][j][dir]!=-1) return dp[i][j][dir];
        int  d = 0, right = 0;
        if(grid[i][j] == 1)
        {
            if(dir == -1)
            {
                d = helper(grid,i,j+1,0,dp);
                right = helper(grid,i+1,j,1,dp);
            }
            else if(dir == 1) //down
            d = helper(grid,i,j+1,0,dp);
            else
            right = helper(grid,i+1,j,1,dp);
        }
        else
       {
            d = helper(grid,i+1,j,1,dp);
            right = helper(grid,i,j+1,0,dp);
       }
    // cout<<i<<" "<<j<<" "<<d+right<<endl;
    if(dir!=-1)
     return dp[i][j][dir]= (d+right)%mod;
    else
    {
        return  (d+right)%mod;
    }
    }
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(2,-1)));
        return helper(grid,0,0,-1,dp);
    }
};