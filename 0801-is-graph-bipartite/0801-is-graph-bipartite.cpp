class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        vector<int> vis(n,0);
        int a = 0;
        // cout<<!a;
        for(int i =0;i<n;i++)
        {
            if(vis[i] == 1)
            continue;
            queue<pair<int,int>> q;
            q.push({i,0});
            color[i] = 0;
            

            while(!q.empty())
            {
                int node = q.front().first;
                int c = q.front().second;
                q.pop();
                vis[node] = 1;
                // cout<<node<<endl;
                for(auto x: graph[node])
                {
                    if(vis[x] == 0)
                    {
                        color[x] = !color[node];
                        q.push({x,!color[node]});
                    }
                    else if(vis[x] == 1 && color[x] == color[node])
                    return false;
                }
            }
        }
        return true;
    }
};