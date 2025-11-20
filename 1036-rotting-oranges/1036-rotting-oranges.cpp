// looks like a bfs
// we need to iteratively run bfs on cells which has rotten oranges
// In the bfs -> we need to traverse only the the cells with fresh oranges. And convert the fresh to rotten oranges.
// After doing it for all rotten oranges. We will check for any fresh oranges. If it is present -> return -1 else we return ans obtained from bfs


class Solution {
public:
    // for checking valid cell
    bool checkConstraints(int x, int y, int m, int n)
    {
        return (x>=0 && x<m && y>=0 && y<n);
    }


    int orangesRotting(vector<vector<int>>& grid) {
        
        // final answer
        int ans = 0;
        int freshOranges = 0;
        int m = grid.size(), n= grid[0].size();
        queue<pair<int, pair<int,int>>> q;
        int dx[] = {1,0,-1,0};
        int dy[] = {0,1,0,-1};
        
        // we need to iteratively run bfs on cells which has rotten oranges
        for(int i =0;i<m;i++)
        {
            for(int j = 0;j<n ;j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({0,{i,j}});
                    grid[i][j] = 3;
                }
                
                if(grid[i][j] == 1)
                freshOranges++;

            }
        }
        while(!q.empty())
        {
            int lvl = q.front().first;
            auto [i,j] = q.front().second;
            q.pop();
            ans = max(lvl,ans);            
            
            for(int k = 0;k<4;k++)
            {
                int new_x = i+dx[k], new_y = j+dy[k];
                // check overflow constraint and fresh oranges
                if(checkConstraints(new_x,new_y,m,n) && grid[new_x][new_y] == 1)
                {
                    q.push({lvl+1,{new_x,new_y}});
                    grid[new_x][new_y] = 3;
                    freshOranges--;
                    
                }

            }
        }
        // check for fresh oranges. If it is present -> return -1 else we return ans obtained from bfs
        if(freshOranges >0 )
        return -1;
        return ans;
    }
};


// 1 2
// 1 0