class Solution {
  public:
    void dfs(vector<vector<char>>& grid,vector<vector<int>>&vis, int i, int j)
    {
        int m = grid.size(), n= grid[0].size();
        if(i<0 || i>=m|| j<0 || j>=n)
        return ;
        grid[i][j] = 'Y';
        vis[i][j] = 1;
        int dx[] = {1,0,-1,0};
        int dy[] = {0,1,0,-1};
        for(int k = 0;k<4;k++)
        {
            int x = i+dx[k], y = j+dy[k];
            if(x>=0 && x<m && y>=0 && y <n && !vis[x][y] && grid[x][y] == 'O')
            dfs(grid,vis,x,y);
        }
    }
    void fill(vector<vector<char>>& grid) {
        // Code here
        int m = grid.size(), n= grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int j = 0;j<n;j++)
        {
            if(!vis[0][j] && grid[0][j] == 'O')
            dfs(grid,vis,0,j);
            if(!vis[m-1][j] && grid[m-1][j] == 'O')
            dfs(grid,vis,m-1,j);
        }
        for(int i = 0;i<m;i++)
        {
            if(!vis[i][0] && grid[i][0] == 'O')
            dfs(grid,vis,i,0);
            if(!vis[i][n-1] && grid[i][n-1] == 'O')
            dfs(grid,vis,i,n-1);
        }
        
        for(int i = 1;i<m;i++)
        {
            for(int j = 1;j<n;j++)
            {
                if(grid[i][j] == 'O')
                grid[i][j] = 'X';
            }
        }
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(grid[i][j] == 'Y')
                grid[i][j] = 'O';
            }
        }
        
    }
};