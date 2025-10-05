class Solution {
public:
    vector<vector<bool>> pacific,atlantic;
    vector<vector<int>>ans;
    int m ,n;
		// vector<vector<int> > pacificAtlantic(vector<vector<int>>& mat) {
		// if(!size(mat)) return ans;
		// m = size(mat), n = size(mat[0]);
		// atlantic = pacific = vector<vector<bool> >(m, vector<bool>(n, false));
		// // perform dfs from all edge cells (ocean-connected cells)
		// for(int i = 0; i < m; i++) dfs(mat, pacific, i, 0), dfs(mat, atlantic, i, n - 1);
		// for(int i = 0; i < n; i++) dfs(mat, pacific, 0, i), dfs(mat, atlantic, m - 1, i);             
		// return ans;
		// }
// void dfs(vector<vector<int> >& mat, vector<vector<bool> >& visited, int i, int j){        
//         if(visited[i][j]) return;
//         visited[i][j] = true;
// 		// if cell reachable from both the oceans, insert into final answer vector
//         if(atlantic[i][j] && pacific[i][j]) ans.push_back(vector<int>{i, j});    
// 		// dfs from current cell only if height of next cell is greater
// /*⬇️*/  if(i + 1 <  m && mat[i + 1][j] >= mat[i][j]) dfs(mat, visited, i + 1, j); 
// /*⬆️*/  if(i - 1 >= 0 && mat[i - 1][j] >= mat[i][j]) dfs(mat, visited, i - 1, j);
// /*➡️*/  if(j + 1 <  n && mat[i][j + 1] >= mat[i][j]) dfs(mat, visited, i, j + 1); 
// /*⬅️*/  if(j - 1 >= 0 && mat[i][j - 1] >= mat[i][j]) dfs(mat, visited, i, j - 1);
//     }
    void dfs(vector<vector<int>>&adj, vector<vector<bool>>& vis, int i ,int j)
    {
        
        if(vis[i][j])             return ;
        vis[i][j] = true;
        if (atlantic[i][j] && pacific[i][j]) ans.push_back(vector<int>{i,j});
        if(i + 1 <  m && adj[i + 1][j] >= adj[i][j]) dfs(adj, vis, i + 1, j);
        if(i - 1 >= 0 && adj[i - 1][j] >= adj[i][j]) dfs(adj, vis, i - 1, j);
        if(j + 1 <  n && adj[i][j + 1] >= adj[i][j]) dfs(adj, vis, i, j + 1);
        if(j - 1 >= 0 && adj[i][j - 1] >= adj[i][j]) dfs(adj, vis, i, j - 1);
    
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& adj) {
        if(!size(adj)) return ans;
        m = adj.size(), n = adj[0].size();
        atlantic = pacific = vector<vector<bool> >(m, vector<bool>(n, false));
        for(int i =0;i<m;i++) dfs(adj,pacific,i,0), dfs(adj,atlantic,i,n-1);
        for(int i =0;i<n;i++) dfs(adj,pacific,0,i), dfs(adj,atlantic,m-1,i);
        return ans;
        
    }
};