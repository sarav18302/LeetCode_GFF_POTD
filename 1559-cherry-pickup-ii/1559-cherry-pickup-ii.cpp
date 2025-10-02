class Solution {
public:
    int helper(vector<vector<int>>& grid, int row,int a_y,int b_y,vector<vector<vector<int>>>&dp)
    {
        int m = grid.size(), n = grid[0].size();
        if(row<0 || row>=m || a_y<0 || a_y>=n || b_y<0 || b_y>=n )
        return -1e5;
        if(row >=m)
        {
            return 0;
        }
        if(dp[row][a_y][b_y]!=-1) return dp[row][a_y][b_y];
        int dy[] ={-1,0,1};
        int cherries = (a_y == b_y)? grid[row][a_y]: grid[row][a_y]+grid[row][b_y];
        int sum = 0;
        for(auto da:dy)
        {
            for(auto db:dy)
            {
                sum = max(sum,helper(grid,row+1,a_y+da,b_y+db,dp));
            }
        }
        
        return dp[row][a_y][b_y] = sum+cherries;

    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(n+1,-1)));
        return helper(grid,0,0,grid[0].size()-1,dp);
    }
};