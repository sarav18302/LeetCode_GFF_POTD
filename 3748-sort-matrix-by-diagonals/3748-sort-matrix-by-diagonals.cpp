class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        map<int,vector<int>>mp;
        int n = grid.size();
        for(int i =0;i<n;i++)
        {
            for(int j =0;j<n;j++)
            {
                int idx = i-j;
                mp[idx].push_back(grid[i][j]);
            }
        }
        for(auto &x: mp)
        {
            if(x.first>=0)
            sort(x.second.begin(),x.second.end(),greater<int>());
            else
            sort(x.second.begin(),x.second.end());
        }
        for(int i=0;i<n;i++)
        {
            for(int j =0;j<n;j++)
            {
                int idx = i-j;
                grid[i][j] = mp[idx][0];
                mp[idx].erase(mp[idx].begin());
            }
        }
        return grid;
    }
};