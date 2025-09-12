class Solution {
public:
    bool check(vector<vector<int>>& grid)
    {
        for(auto row: grid)
        {
            for(auto x: row)
            {
                if(x == 0)
                return false;
            }
        }
        return true;
    }
    int helper(vector<vector<int>>& grid, int i,int j)
    {
        int m = grid.size(), n= grid[0].size();
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j] == -1 || grid[i][j] == -2)
        return 0;
        if(grid[i][j] == 2 & check(grid))
        return 1;
        else if(grid[i][j] == 2)
        return 0;

        int temp = grid[i][j];
        grid[i][j] = -2;
        int dx[] = {1,0,-1,0};
        int dy[] = {0,1,0,-1};
        int cnt = 0;
        for(int k =0;k<4;k++)
        {
            int x = i+dx[k], y = j+dy[k];
            cnt+=helper(grid,x,y);
            
        }
        grid[i][j] = temp;
        return cnt;

    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size(), n= grid[0].size();
        for(int i =0;i<m;i++)
        {
            for(int j =0;j<n;j++)
            {
                if(grid[i][j] == 1)
                {
                    return helper(grid,i,j);
                }
            }
        }
        return 0;
    }
};