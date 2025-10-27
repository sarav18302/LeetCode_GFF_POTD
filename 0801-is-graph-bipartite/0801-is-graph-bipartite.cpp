class Solution {
public:
    bool dfs(int curr,int parent, vector<vector<int>>& graph,vector<int>&vis,vector<int>&color)
    {
        vis[curr] = 1;
        for(auto x: graph[curr])
        {
            if(!vis[x])
            {
                color[x] = !color[curr];
                if(!dfs(x,curr,graph,vis,color))
                return false;
            }
            else if(color[x] == color[curr] && x!=parent)
            {
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,0);
        vector<int> color(n,-1);
        for(int i =0;i<n;i++)
        {
            if(!vis[i] )
            {
                color[i] = 0;
                if(!dfs(i,-1,graph,vis,color))
                return false;
            }
        }
        return true;
    }
};