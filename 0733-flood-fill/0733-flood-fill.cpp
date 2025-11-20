// single source grid traversal problem (DFS/BFS)
// I am chossing DFS because it helps in reaching the necessary nodes faster and it is more intutive than BFS.
// Check if the orginal color is different and perform dfs


class Solution {
public:
    void dfs(vector<vector<int>>&image, vector<vector<int>>&vis, int row, int col , int color)
    {
        int m = image.size(), n = image[0].size();
        cout<<m<<" "<<n<<endl;
        vis[row][col] = 1;
        int temp = image[row][col];
        // cout<<temp<<endl;
        image[row][col] = color;
        int d[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
        for(int k = 0;k<4;k++)
        {
            int new_row = row+d[k][0];
            int new_col = col+d[k][1];
            // cout<<new_row<<" "<<new_col<<endl;
            if(new_row >=0 && new_row < m && new_col>=0 && new_col <n && vis[new_row][new_col] == 0 && image[new_row][new_col] == temp)
            dfs(image,vis, new_row,new_col,color);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(), n = image[0].size();
        if(image[sr][sc] == color)
        return image;
        vector<vector<int>> vis(m, vector<int>(n,0));
        dfs(image, vis, sr,sc,color);
        return image;
    }
};