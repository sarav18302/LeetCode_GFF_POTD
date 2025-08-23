class Solution {
public:
    int minarea(vector<vector<int>>& grid,int st_i,int en_i,int st_j, int en_j)
    {
        int srow = 1e9, erow = -1, scol = 1e9,ecol = -1,found = 0;
        for(int i =st_i;i<=en_i;i++)
        {
            for(int j = st_j;j<=en_j;j++)
            {
                if(grid[i][j])
                {
                    srow = min(srow,i);
                    erow = max(erow,i);
                    scol = min(scol,j);
                    ecol = max(ecol,j);
                    found = 1;
                }
            }
        }
        return (found ==0)?0:(erow-srow+1)*(ecol-scol+1);
    }
    int minimumSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 1e9,one = 1e9,two =1e9,three =1e9;
        // Case 1:
         /*
        -------------
        |    (1)    |
        |           |
        -------------
        | (2) | (3) |
        |     |     |
        -------------
        */
        for(int i=0;i<m;i++)
        {
            one = minarea(grid,0,i,0,n-1);
            for(int j =0;j<n;j++)
            {
                two = minarea(grid,i+1,m-1,0,j);
                three = minarea(grid,i+1,m-1,j+1,n-1);
                ans = min(ans,one+two+three);
            }
        }

        // Case 2:
        /*
        -------------
        |     | (2) |
        |     |     |
          (1) -------
        |     |     |
        |     | (3) |
        -------------
        */
        for(int j=0;j<n;j++)
        {
            one = minarea(grid,0,m-1,0,j);
            for(int i =0;i<m;i++)
            {
                two = minarea(grid,0,i,j+1,n-1);
                three = minarea(grid,i+1,m-1,j+1,n-1);
                ans = min(ans,one+two+three);
            }
        }

        // Case 3:
        /*
        -------------
        |     |     |
        | (2) |     |
        ------- (1) |
        |     |     |
        | (3) |     |
        -------------
        */
        for(int j=n-1;j>=0;j--)
        {
            one = minarea(grid,0,m-1,j+1,n-1);
            for(int i =0;i<m;i++)
            {
                two = minarea(grid,0,i,0,j);
                three = minarea(grid,i+1,m-1,0,j);
                ans = min(ans,one+two+three);
            }
        }

        // Case 4:
         /*
        -------------
        | (2) | (3) |
        |     |     |
        ------------
        |           |
        |    (1)    |
        -------------
        */
        for(int i=m-1;i>=0;i--)
        {
            one = minarea(grid,i+1,m-1,0,n-1);
            for(int j =0;j<n;j++)
            {
                two = minarea(grid,0,i,0,j);
                three = minarea(grid,0,i,j+1,n-1);
                ans = min(ans,one+two+three);
            }
        }

        // Case 5:
        /*
        -------------
        |    (1)    |
        -------------
        |    (2)    |
        -------------
        |    (3)    |
        -------------
        */

        for(int i=0;i<m;i++)
        {
            
            for(int j =i+1;j<m;j++)
            {
                one = minarea(grid,0,i,0,n-1);
                two = minarea(grid,i+1,j,0,n-1);
                three = minarea(grid,j+1,m-1,0,n-1);
                ans = min(ans,one+two+three);
            }
        }

        // Case 6:
         /*
        -------------
        |   |   |   |
        |   |   |   |
        |(1)|(2)|(3)|
        |   |   |   |
        |   |   |   |
        -------------
        */ 
         for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                one = minarea(grid, 0, m-1, 0, i);
                two = minarea(grid, 0, m-1, i+1, j);
                three = minarea(grid, 0, m-1, j+1, n-1);
                ans = min(ans, one + two + three);
            }
        }
        return ans;
    }
};