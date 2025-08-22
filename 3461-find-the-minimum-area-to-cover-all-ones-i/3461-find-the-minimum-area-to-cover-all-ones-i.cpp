class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int minrow =m, maxrow = 0;
        for(int i =0;i<m;i++)
        {
            for(int j =0;j<n;j++)
            {
                if(grid[i][j] == 1)
                {
                    if(minrow > i)
                    minrow = i;
                    if(maxrow < i)
                    maxrow = i;
                }
            }
        }
        int mincol=  n, maxcol = 0;
        for(int j = 0;j<n;j++)
        {
            for(int i =0;i<m;i++)
            {
                if(grid[i][j] == 1)
                {
                    if(mincol > j)
                    mincol = j;
                    if(maxcol <j)
                    maxcol = j;
                }
                
            }
        }
        // cout<<maxrow<<" "<<minrow<<" "<<maxcol<<" "<<mincol<<endl;
        return (maxrow-minrow+1)*(maxcol-mincol+1);
    }
    
};